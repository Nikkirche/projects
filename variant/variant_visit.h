#pragma once
#include "iostream"
#include "variant_stuff.h"
#include <array>
#include <functional>
namespace visiting {
template <std::size_t... I>
struct invoker {
  template <typename Visitor, typename... Variants>
  static constexpr decltype(auto) invoke(Visitor v, Variants... variants) {
    return std::invoke(static_cast<Visitor>(v), get<I>(static_cast<Variants>(variants).holder)...);
  }
};
template <typename Visitor, typename... Variants, std::size_t... I>
constexpr auto gen_invoker(std::index_sequence<I...>) {
  return &invoker<I...>::template invoke<Visitor, Variants...>;
}
template <typename T>
constexpr T&& at_impl(T&& elem) {
  return std::forward<T>(elem);
};
template <typename T, typename... Indexes>
constexpr auto&& at_impl(T&& elements, std::size_t I, Indexes... indexes) {
  return at_impl(static_cast<T>(elements)[I], indexes...);
}

template <typename T, typename... Indexes>
constexpr auto&& at(T&& elements, Indexes... indexes) {
  return at_impl(std::forward<T>(elements), indexes...);
}

template <typename Visitor, typename... Variants, std::size_t... I>
constexpr auto gen_table_impl(std::index_sequence<I...> indexes) {
  return gen_invoker<Visitor, Variants...>(indexes);
}

template <typename Visitor, typename... Variants, std::size_t... Accum, std::size_t... Indexes, typename... Rest>
constexpr auto gen_table_impl(std::index_sequence<Accum...>, std::index_sequence<Indexes...>, Rest... rest) {
  return std::array{gen_table_impl<Visitor, Variants...>(std::index_sequence<Accum..., Indexes>{}, rest...)...};
}
template <class Tp>
struct counter {};
template <typename Visitor, typename... Variants>
constexpr auto gen_table() {
  return gen_table_impl<Visitor, Variants...>(
      std::index_sequence<>{}, std::make_index_sequence<variant_size_v<std::remove_reference_t<Variants>>>{}...);
}
template <std::size_t I, typename Visitor, typename... Variants>
constexpr auto gen_dig_table_impl() {
  return gen_invoker<Visitor, Variants...>(std::index_sequence<(counter<Variants>{}, I)...>{});
}
template <typename Visitor, typename... Variants, std::size_t... I>
constexpr auto gen_dig_table_impl(std::index_sequence<I...>) {
  return std::array{gen_dig_table_impl<I, Visitor, Variants...>()...};
}
template <typename Visitor, typename Variant, typename... Variants>
constexpr auto gen_dig_table() {
  constexpr auto I = std::make_index_sequence<variant_size_v<std::remove_reference_t<Variant>>>{};
  return gen_dig_table_impl<Visitor, Variant, Variants...>(I);
}
template <typename Visitor, typename... Variants>
constexpr decltype(auto) visit_at(std::size_t index, Visitor&& visitor, Variants&&... variants) {
  constexpr auto table = gen_dig_table<Visitor&&, Variants&&...>();
  return table[index](std::forward<Visitor>(visitor), std::forward<Variants>(variants)...);
}

} // namespace visiting
template <typename Visitor, typename... Variants>
constexpr decltype(auto) visit(Visitor&& visitor, Variants&&... variants) {
  constexpr auto table = visiting::gen_table<Visitor&&, Variants&&...>();
  bool state[] = {variants.valueless_by_exception()...};
  for (auto&& t : state) {
    if (t) {
      throw bad_variant_access();
    }
  }
  return visiting::at(table, variants.index()...)(std::forward<Visitor>(visitor), std::forward<Variants>(variants)...);
}
