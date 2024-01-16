#pragma once
#include "variant_details.h"
#include <concepts>
#include <iostream>
#include <typeinfo>
template <bool is_trivial, typename... Types>
struct variant_holder {
  std::size_t ind{0};
  details::variant_union<details::is_destructible<Types...>, Types...> holder;

public:
  variant_holder() = default;

  ~variant_holder() = default;
};
template <typename... Types>
struct variant_holder<false, Types...> {
  std::size_t ind{0};
  details::variant_union<details::is_destructible<Types...>, Types...> holder;
  variant_holder() = default;
  ~variant_holder() {
    details::reset(holder, ind);
  }
};
template <typename... Types>
struct variant : public variant_holder<details::is_destructible<Types...>, Types...> {
private:
  void destroy() {
    if (this->ind != variant_npos) {
      visit(
          [](auto& a) {
            using type = std::remove_reference_t<decltype(a)>;
            a.~type();
          },
          *this);
      this->ind = variant_npos;
    }
  }
  template <typename T>
  void abstract_copy(T&& rhs) {
    visiting::visit_at(
        rhs.ind,
        [this](auto& a, auto&& b) {
          this->ind = variant_npos;
          std::construct_at(std::addressof(a), std::forward<decltype(b)>(b));
        },
        *this, std::forward<T>(rhs));
  }
  template <typename Arg>
  void abstract_assign_from_arg(Arg&& arg) {
    visiting::visit_at(
        this->ind,
        [this, &arg](auto& a) {
          if constexpr (std::is_assignable_v<decltype(a), Arg>) {
            this->ind = variant_npos;
            a = std::forward<Arg>(arg);
          }
        },
        *this);
  }
  template <typename T>
  void abstract_assign(T&& rhs) {
    visiting::visit_at(
        rhs.ind,
        [this](auto& a, auto&& b) {
          this->ind = variant_npos;
          a = std::forward<decltype(b)>(b);
        },
        *this, std::forward<T>(rhs));
  }

public:
  constexpr variant() noexcept(details::is_nothrow_default_constructible_v<variant_alternative_t<0, variant<Types...>>>)
      requires details::is_default_constructible_v<variant_alternative_t<0, variant<Types...>>> = default;

  constexpr variant() = delete;

  template <std::size_t I>
  constexpr variant(in_place_index_t<I>) requires details::is_valid_index<I, variant<Types...>> {
    this->ind = variant_npos;
    details::emplace<I>(this->holder);
    this->ind = I;
  }
  template <std::size_t I, typename... Args>
      constexpr variant(in_place_index_t<I>, Args... args) requires(variant_size_v<variant<Types...>> > I) &&
      (sizeof...(args) != 0) {
    this->ind = variant_npos;
    details::emplace<I>(this->holder, std::forward<Args>(args)...);
    this->ind = I;
  }

  template <typename T>
  constexpr variant(in_place_type_t<T>)
      requires std::disjunction_v<std::is_same<T, Types>...>&& details::is_default_constructible_v<T> {
    constexpr auto I = details::index_by_type<T, Types...>;
    this->ind = variant_npos;
    details::emplace<I>(this->holder);
    this->ind = I;
  }

  template <typename T, typename... Args>
      constexpr variant(in_place_type_t<T>, Args... args) requires(sizeof...(args) != 0) &&
      std::disjunction_v<std::is_same<T, Types>...> {
    constexpr auto I = details::index_by_type<T, Types...>;
    this->ind = variant_npos;
    details::emplace<I>(this->holder, std::forward<Args>(args)...);
    this->ind = I;
  }

  template <typename T>
  constexpr variant(T&& t) noexcept(
      details::is_nothrow_converting<T, Types...>) requires details::is_converting<T, Types...> {
    constexpr auto I = details::converting_ind<T, Types...>;
    this->ind = variant_npos;
    details::emplace<I>(this->holder, std::forward<T>(t));
    this->ind = I;
  }

  template <typename T>
  constexpr variant&
  operator=(T&& t) noexcept(details::is_nothrow_converting<T, Types...>) requires details::is_converting<T, Types...> {
    constexpr auto I = details::converting_ind<T, Types...>;
    using Type = variant_alternative_t<I, variant<Types...>>;
    if (this->ind == I) {
      abstract_assign_from_arg(std::forward<T>(t));
      this->ind = I;
    } else if constexpr (std::is_nothrow_constructible_v<Type, T> || !std::is_nothrow_move_constructible_v<Type>) {
      this->emplace<I>(std::forward<T>(t));
    } else {
      this->emplace<I>(Type(std::forward<T>(t)));
    }
    return *this;
  }

  template <class T>
  constexpr friend bool holds_alternative(const variant& var) {
    return details::index_by_type<T, Types...> == var.index();
  }

  constexpr std::size_t index() const {
    return this->ind;
  }

  constexpr variant(const variant& other) requires details::is_copy_constructible_v<Types...> {
    if (!other.valueless_by_exception()) {
      abstract_copy(other);
    }
    this->ind = other.ind;
  }

  constexpr variant(const variant& other) requires details::is_trivially_copy_constructible_v<Types...> = default;

  constexpr variant(variant&& other) noexcept(
      details::is_noexcept_move_constructible_v<Types...>) requires details::is_move_constructible_v<Types...> {
    if (!other.valueless_by_exception()) {
      abstract_copy(std::move(other));
    }
    this->ind = other.ind;
  }

  constexpr variant(variant&& other) requires details::is_trivially_move_constructible_v<Types...> = default;
  constexpr variant& operator=(const variant& other) requires details::is_copy_assignable_v<Types...> {
    if (this->valueless_by_exception() && other.valueless_by_exception()) {
      return *this;
    } else if (other.valueless_by_exception()) {
      destroy();
    } else if (this->ind != other.ind) {
      destroy();
      abstract_copy(other);
      this->ind = other.ind;
    } else if (this->ind == other.ind) {
      abstract_assign(other);
      this->ind = other.ind;
    }
    return *this;
  }

  constexpr variant&
  operator=(const variant& other) requires details::is_trivially_copy_assignable_v<Types...> = default;
  constexpr variant& operator=(variant&& other) noexcept(
      details::is_noexcept_move_assignable_v<Types...>) requires details::is_move_assignable_v<Types...> {
    if (this->valueless_by_exception() && other.valueless_by_exception()) {
      return *this;
    } else if (other.valueless_by_exception()) {
      destroy();
    } else if (this->ind != other.ind) {
      destroy();
      abstract_copy(std::move(other));
      this->ind = other.ind;
    } else if (this->ind == other.ind) {
      abstract_assign(std::move(other));
      this->ind = other.ind;
    }
    return *this;
  }

  constexpr variant& operator=(variant&& other) requires details::is_trivially_move_assignable_v<Types...> = default;

  constexpr bool valueless_by_exception() const noexcept {
    return index() == variant_npos;
  }

  template <typename T, typename... Args>
  constexpr auto& emplace(Args&&... args) {
    destroy();
    constexpr auto I = details::index_by_type<T, Types...>;
    details::emplace<I>(this->holder, std::forward<Args>(args)...);
    this->ind = I;
    return details::get<I>(this->holder);
  }

  template <std::size_t I, typename... Args>
  variant_alternative_t<I, variant<Types...>>& emplace(Args&&... args) {
    destroy();
    details::emplace<I>(this->holder, std::forward<Args>(args)...);
    this->ind = I;
    return details::get<I>(this->holder);
  }

  template <typename T>
  constexpr friend decltype(auto) get(const variant& var) {
    return details::get<details::index_by_type<T, Types...>>(var.holder);
  }

  template <typename T>
  constexpr T&& get(variant&& var) {
    return get<details::index_by_type<T, Types...>>(var);
  }

  constexpr void swap(variant& rhs) {
    if (this->valueless_by_exception() && rhs.valueless_by_exception()) {
      return;
    }
    if (this->index() == rhs.index()) {
      visiting::visit_at(
          this->ind,
          [](auto& a, auto& b) {
            using std::swap;
            swap(a, b);
          },
          *this, rhs);
    } else {
      std::swap(*this, rhs);
    }
  }
};

// Comparision operators
template <typename... Types>
bool operator==(const variant<Types...>& one, const variant<Types...>& second) {
  if (one.index() != second.index()) {
    return false;
  }
  if (one.valueless_by_exception()) {
    return true;
  }
  return visiting::visit_at(one.index(), std::equal_to{}, one, second);
}

template <typename... Types>
bool operator!=(const variant<Types...>& one, const variant<Types...>& second) {
  if (one.index() != second.index()) {
    return true;
  }
  if (one.valueless_by_exception()) {
    return false;
  }
  return visiting::visit_at(one.index(), std::not_equal_to{}, one, second);
}

template <typename... Types>
bool operator<(const variant<Types...>& one, const variant<Types...>& second) {
  if (second.valueless_by_exception()) {
    return false;
  } else if (one.valueless_by_exception()) {
    return true;
  } else if (one.ind < second.ind) {
    return true;
  } else if (one.ind > second.ind) {
    return false;
  }
  return visiting::visit_at(one.index(), std::less{}, one, second);
}

template <typename... Types>
bool operator>(const variant<Types...>& one, const variant<Types...>& second) {
  if (one.valueless_by_exception()) {
    return false;
  } else if (second.valueless_by_exception()) {
    return true;
  } else if (one.ind > second.ind) {
    return true;
  } else if (one.ind < second.ind) {
    return false;
  }
  return visiting::visit_at(one.index(), std::greater{}, one, second);
}

template <typename... Types>
bool operator<=(const variant<Types...>& one, const variant<Types...>& second) {
  if (one.valueless_by_exception()) {
    return true;
  } else if (second.valueless_by_exception()) {
    return false;
  } else if (one.ind < second.ind) {
    return true;
  } else if (one.ind > second.ind) {
    return false;
  }
  return visiting::visit_at(one.index(), std::less_equal{}, one, second);
}

template <typename... Types>
bool operator>=(const variant<Types...>& one, const variant<Types...>& second) {
  if (second.valueless_by_exception()) {
    return true;
  } else if (one.valueless_by_exception()) {
    return false;
  } else if (one.ind > second.ind) {
    return true;
  } else if (one.ind < second.ind) {
    return false;
  }
  return visiting::visit_at(one.index(), std::greater_equal{}, one, second);
}

template <std::size_t I, typename... Types>
constexpr variant_alternative_t<I, variant<Types...>>& get(variant<Types...>& var) {
  return details::abstract_get<I>(var);
}

template <std::size_t I, typename... Types>
constexpr const variant_alternative_t<I, variant<Types...>>& get(const variant<Types...>& var) {
  return details::abstract_get<I>(var);
}

template <std::size_t I, typename... Types>
constexpr variant_alternative_t<I, variant<Types...>>&& get(variant<Types...>&& var) {
  return details::abstract_get<I>(std::move(var));
}

template <std::size_t I, typename... Types>
constexpr const variant_alternative_t<I, variant<Types...>>&& get(const variant<Types...>&& var) {
  return details::abstract_get<I>(std::move(var));
}

template <std::size_t I, typename... Types>
constexpr std::add_pointer_t<variant_alternative_t<I, variant<Types...>>> get_if(variant<Types...>* var) {
  return details::abstract_get_if<I>(var);
}

template <std::size_t I, typename... Types>
constexpr std::add_pointer_t<const variant_alternative_t<I, variant<Types...>>> get_if(const variant<Types...>* var) {
  return details::abstract_get_if<I>(var);
}

template <typename T, typename... Types>
constexpr const auto* get_if(const variant<Types...>* var) {
  constexpr auto I = details::index_by_type<T, Types...>;
  return details::abstract_get_if<I>(var);
}

template <typename T, typename... Types>
constexpr auto* get_if(variant<Types...>* var) {
  constexpr auto I = details::index_by_type<T, Types...>;
  return details::abstract_get_if<I>(var);
}
