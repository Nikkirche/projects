#pragma once
#include "variant_visit.h"
namespace details {

template <typename Type>
concept is_default_constructible_v = std::is_default_constructible_v<Type>;
template <typename Type>
concept is_nothrow_default_constructible_v =
    std::is_nothrow_default_constructible_v<Type> && is_default_constructible_v<Type>;

template <typename... Types>
concept is_move_constructible_v = std::conjunction_v<std::is_move_constructible<Types>...>;
template <typename... Types>
concept is_noexcept_move_constructible_v =
    std::conjunction_v<std::is_nothrow_move_constructible<Types>...> && is_move_constructible_v<Types...>;
template <typename... Types>
concept is_trivially_move_constructible_v =
    std::conjunction_v<std::is_trivially_move_constructible<Types>...> && is_noexcept_move_constructible_v<Types...>;

template <typename... Types>
concept is_copy_constructible_v = std::conjunction_v<std::is_copy_constructible<Types>...>;

template <typename... Types>
concept is_trivially_copy_constructible_v =
    std::conjunction_v<std::is_trivially_copy_constructible<Types>...> && is_copy_constructible_v<Types...>;

template <typename... Types>
concept is_copy_assignable_v =
    std::conjunction_v<std::is_copy_assignable<Types>...> && is_copy_constructible_v<Types...>;
template <typename... Types>
concept is_trivially_copy_assignable_v = std::conjunction_v<std::is_trivially_copy_assignable<Types>...> &&
                                         is_copy_assignable_v<Types...> && is_trivially_copy_constructible_v<Types...>;

template <typename... Types>
concept is_move_assignable_v =
    std::conjunction_v<std::is_move_assignable<Types>...> && is_move_constructible_v<Types...>;
template <typename... Types>
concept is_noexcept_move_assignable_v = std::conjunction_v<std::is_nothrow_move_assignable<Types>...> &&
                                        is_move_assignable_v<Types...> && is_noexcept_move_constructible_v<Types...>;
template <typename... Types>
concept is_trivially_move_assignable_v =
    std::conjunction_v<std::is_trivially_move_assignable<Types>...> && is_noexcept_move_assignable_v<Types...> &&
    is_trivially_move_constructible_v<Types...>;
template <typename T, typename V>
concept is_valid_converting = requires(T && t) {
  V{std::forward<T>(t)};
};

template <typename T, typename... Types>
concept is_converting = (... || is_valid_converting<T, Types>);

template <typename T, typename V>
concept is_nothrow_valid_converting = requires(T && t) {
  V{std::forward<T>(t)};
}
&&std::is_nothrow_constructible_v<V, T>;
template <typename T, typename... Types>
concept is_nothrow_converting = (... || (is_converting<T, Types>)) && (... || (is_nothrow_valid_converting<T, Types>));
template <typename... Types>
concept is_destructible = std::conjunction_v<std::is_trivially_destructible<Types>...>;

template <std::size_t I, typename Variant>
concept is_valid_index =
    (variant_size_v<Variant> > I) && details::is_default_constructible_v<variant_alternative_t<I, Variant>>;
template <bool is_trivial, typename Head, typename... Tail>
union variant_union {
  Head head;
  variant_union<is_destructible<Tail...>, Tail...> tail;
  constexpr variant_union() noexcept requires details::is_default_constructible_v<Head> : head() {}
  constexpr variant_union() {}
  constexpr ~variant_union() = default;
  constexpr variant_union(const variant_union&) = default;
};
template <typename Head, typename... Tail>
union variant_union<false, Head, Tail...> {
  Head head;
  variant_union<is_destructible<Tail...>, Tail...> tail;
  constexpr variant_union() noexcept requires details::is_default_constructible_v<Head> : head() {}
  constexpr variant_union() {}
  constexpr ~variant_union() {}
  constexpr variant_union(const variant_union&) = default;
};

template <typename Head>
union variant_union<true, Head> {
  Head head;
  constexpr variant_union() noexcept requires details::is_default_constructible_v<Head> : head() {}
  constexpr variant_union() {}
  constexpr ~variant_union() = default;
  constexpr variant_union(const variant_union&) = default;
};
template <typename Head>
union variant_union<false, Head> {
  Head head;
  constexpr variant_union() noexcept requires details::is_default_constructible_v<Head> : head() {}
  constexpr variant_union() {}
  constexpr ~variant_union() {}
  constexpr variant_union(const variant_union&) = default;
};

template <std::size_t I, typename Holder, typename... Args>
constexpr void emplace(Holder&& holder, Args&&... args) {
  if constexpr (I == 0) {
    std::construct_at(std::addressof(holder.head), std::forward<Args>(args)...);
  } else {
    std::construct_at(std::addressof(holder.tail));
    emplace<I - 1>(std::forward<Holder>(holder).tail, std::forward<Args>(args)...);
  }
}

template <std::size_t I, typename Holder>
constexpr auto&& get(Holder&& holder) {
  if constexpr (I == 0) {
    return std::forward<Holder>(holder).head;
  } else {
    return get<I - 1>(std::forward<Holder>(holder).tail);
  }
}

template <typename... Types>
using storage_t = details::variant_union<std::conjunction_v<std::is_trivially_destructible<Types>...>, Types...>;

template <typename Head, typename... Tail>
constexpr void reset(storage_t<Head, Tail...>& holder, const std::size_t I) {
  if (I == 0) {
    holder.head.~Head();
  } else if constexpr (sizeof...(Tail) != 0) {
    reset<Tail...>(holder.tail, I - 1);
  }
}
template <std::size_t N, typename T, typename Head, typename... Tail>
struct index_by_type_rec {
  static constexpr std::size_t value = std::is_same_v<T, Head> ? N : index_by_type_rec<N + 1, T, Tail...>::value;
};
template <std::size_t N, typename T, typename Head>
struct index_by_type_rec<N, T, Head> {
  static constexpr std::size_t value = N;
};
template <typename T, typename... Tail>
constexpr std::size_t index_by_type = index_by_type_rec<0, T, Tail...>::value;

template <std::size_t I, typename Var>
constexpr auto&& abstract_get(Var&& var) {
  if (I == var.ind) {
    return get<I>(std::forward<Var>(var).holder);
  } else {
    throw bad_variant_access();
  }
}
template <std::size_t I, typename Variant>
constexpr auto* abstract_get_if(Variant* var) {

  return var->index() == I ? std::addressof(get<I>(*var)) : nullptr;
}
template <typename T, std::size_t I, typename Type, typename... Types>
struct index_lookuper : index_lookuper<T, I + 1, Types...> {
  using index_lookuper<T, I + 1, Types...>::lookup;
  constexpr static std::integral_constant<std::size_t, I> lookup(Type) requires is_valid_converting<T, Type[]>;
};
template <typename T, std::size_t I, typename Type>
struct index_lookuper<T, I, Type> {
  constexpr static std::integral_constant<std::size_t, I> lookup(Type) requires is_valid_converting<T, Type[]>;
};
template <typename T, typename... Types>
constexpr size_t converting_ind = decltype(index_lookuper<T, 0, Types...>::lookup(std::declval<T>()))();
} // namespace details
