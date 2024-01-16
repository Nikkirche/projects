#pragma once
#include <tuple>
#include <type_traits>
template <typename... Types>
struct variant;
template <typename Variant>
struct variant_size;

template <typename... Types>
struct variant_size<variant<Types...>> : std::integral_constant<size_t, sizeof...(Types)> {};

template <typename Variant>
constexpr std::size_t variant_size_v = variant_size<Variant>::value;

template <typename... Types>
constexpr std::size_t variant_size_v<variant<Types...>> = sizeof...(Types);
template <typename... Types>
constexpr std::size_t variant_size_v<const variant<Types...>> = sizeof...(Types);

template <std::size_t N, typename... Types>
struct variant_alternative;

template <typename T, typename... Types>
struct variant_alternative<0, variant<T, Types...>> {
  using type = T;
};

template <std::size_t N, typename T, typename... Types>
struct variant_alternative<N, variant<T, Types...>> {
  using type = typename variant_alternative<N - 1, variant<Types...>>::type;
};
template <std::size_t N, typename T, typename... Types>
struct variant_alternative<N, const variant<T, Types...>> {
  using type = const typename variant_alternative<N - 1, variant<Types...>>::type;
};

template <std::size_t N, typename... Types>
using variant_alternative_t = typename variant_alternative<N, Types...>::type;

template <class Type>
struct in_place_type_t {

  explicit in_place_type_t() = default;
};
template <class Type>
inline constexpr in_place_type_t<Type> in_place_type{};

template <std::size_t I>
struct in_place_index_t {

  explicit in_place_index_t() = default;
};
template <std::size_t I>
inline constexpr in_place_index_t<I> in_place_index{};
struct bad_variant_access : public std::exception {
  const char* what() const noexcept override {
    return "invalid index";
  }
};
inline constexpr std::size_t variant_npos = -1;
