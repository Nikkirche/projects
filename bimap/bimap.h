#pragma once

#include "map.h"
#include <cstddef>
#include <stdexcept>
template <class L, class R, class CL, class CR>
struct bimap;

template <typename Left, typename Right, typename CompareLeft = std::less<Left>,
          typename CompareRight = std::less<Right>>
struct bimap {
private:
  using left_t = Left;
  using right_t = Right;
  using element = details::bi_node<Left, Right>;
  using left_map_t = details::map<element, Left, true, CompareLeft>;
  using right_map_t = details::map<element, Right, false, CompareRight>;

  left_map_t left_map;
  right_map_t right_map;
  size_t length = 0;

  template <class Key, class Value, bool isLeft>
  class iterator {
    using value_type = const Key;
    using reference = value_type&;
    using pointer = value_type*;
    using node_p = details::node<isLeft>*;
    using self_type = iterator;
    using key_node_p = details::node_key<Key, isLeft>*;
    using reverse_type = iterator<Value, Key, !isLeft>;
    using node_r = details::node<!isLeft>*;
    using base_p = details::base_node*;
    using suc = details::successor;

    base_p i;
    template <class L, class R, class CL, class CR>
    friend struct bimap;

    node_p base_to_node(base_p b) const {
      return static_cast<node_p>(b);
    };

  public:
    iterator(base_p p) : i(p) {}
    // Элемент на который сейчас ссылается итератор.
    // Разыменование итератора end_left() неопределено.
    // Разыменование невалидного итератора неопределено.
    reference operator*() const {
      return static_cast<key_node_p>(base_to_node(i))->key;
    }
    pointer operator->() const {
      return &((static_cast<key_node_p>(base_to_node(i)))->key);
    }
    self_type& operator++() {
      i = suc::next(i);
      return *this;
    }

    self_type& operator--() {
      i = suc::prev(i);
      return *this;
    }

    self_type operator++(int) {
      self_type old = *this;
      i = suc::next(i);
      return old;
    }

    self_type operator--(int) {
      self_type old = *this;
      i = suc::prev(i);
      return old;
    }

    reverse_type flip() const {
      return reverse_type(static_cast<base_p>(static_cast<node_r>(
          i->parent->parent != i ? static_cast<element*>(static_cast<node_p>(i))
                                 : static_cast<node_r>((i->parent)))));
    }

    bool operator==(const self_type& rhs) const {

      return rhs.i == i;
    }

    bool operator!=(const self_type& rhs) const {

      return rhs.i != i;
    }
  };

public:
  using left_iterator = iterator<Left, Right, true>;
  using right_iterator = iterator<Right, Left, false>;

  // Создает bimap не содержащий ни одной пары.
  bimap(CompareLeft compare_left = CompareLeft(),
        CompareRight compare_right = CompareRight())
      : left_map(compare_left), right_map(compare_right, end_left().i) {}

  // Конструкторы от других и присваивания
  bimap(bimap const& other) : left_map(), right_map(end_left().i) {
    for (auto it = other.begin_left(); it != other.end_left(); it++) {
      insert(*it, *it.flip());
    }
  }

  bimap(bimap&& other) noexcept {
    swap(other);
  }

  bimap& operator=(const bimap& other) {
    if (this != &other) {
      bimap tmp = bimap(other);
      swap(tmp);
    }
    return *this;
  }

  bimap& operator=(bimap&& other) noexcept {
    if (this != &other) {
      swap(other);
    }
    return *this;
  }

  void swap(bimap& other) {
    left_map.swap(other.left_map);
    right_map.swap(other.right_map);
    std::swap(static_cast<CompareLeft&>(left_map),
              static_cast<CompareLeft&>(other.left_map));
    std::swap(static_cast<CompareRight&>(right_map),
              static_cast<CompareRight&>(other.right_map));
  }
  // Деструктор. Вызывается при удалении объектов bimap.
  // Инвалидирует все итераторы ссылающиеся на элементы этого bimap
  // (включая итераторы ссылающиеся на элементы следующие за последними).
  ~bimap() {
    clear();
  }

  left_iterator insert(left_t const& left, right_t const& right) {
    return insert_forward<const left_t&, const right_t&>(left, right);
  }
  left_iterator insert(left_t const& left, right_t&& right) {
    return insert_forward<const left_t&, right_t>(left, std::move(right));
  }
  left_iterator insert(left_t&& left, right_t const& right) {
    return insert_forward<left_t, const right_t&>(std::move(left), right);
  }
  left_iterator insert(left_t&& left, right_t&& right) {
    return insert_forward(std::move(left), std::move(right));
  }

  // Удаляет элемент и соответствующий ему парный.
  // erase невалидного итератора неопределен.
  // erase(end_left()) и erase(end_right()) неопределены.
  // Пусть it ссылается на некоторый элемент e.
  // erase инвалидирует все итераторы ссылающиеся на e и на элемент парный к e.
  left_iterator erase_left(left_iterator it) {
    return erase(it, it.flip()).first;
  }
  // Аналогично erase, но по ключу, удаляет элемент если он присутствует, иначе
  // не делает ничего Возвращает была ли пара удалена
  bool erase_left(left_t const& left) {
    left_iterator it = left_map.find(left);
    if (it != end_left()) {
      erase(it, it.flip());
      return true;
    }
    return false;
  }

  right_iterator erase_right(right_iterator it) {
    return erase(it.flip(), it).second;
  }
  bool erase_right(right_t const& right) {
    right_iterator it = right_map.find(right);
    if (it != end_right()) {
      erase(it.flip(), it);
      return true;
    }
    return false;
  }

  // erase от ренжа, удаляет [first, last), возвращает итератор на последний
  // элемент за удаленной последовательностью
  left_iterator erase_left(left_iterator first, left_iterator last) {
    left_iterator it = first;
    while (it != last) {
      it = erase_left(it);
    }
    return it;
  }
  right_iterator erase_right(right_iterator first, right_iterator last) {
    right_iterator it = first;
    while (it != last) {
      it = erase_right(it);
    }
    return it;
  }

  // Возвращает итератор по элементу. Если не найден - соответствующий end()
  left_iterator find_left(left_t const& left) const {
    return left_iterator(left_map.find(left));
  }
  right_iterator find_right(right_t const& right) const {
    return right_iterator(right_map.find(right));
  }

  // Возвращает противоположный элемент по элементу
  // Если элемента не существует -- бросает std::out_of_range
  right_t const& at_left(left_t const& key) const {
    auto iter = find_left(key);
    if (iter == end_left()) {
      throw std::out_of_range("element with given key don't exist");
    }
    return *(iter.flip());
  }
  left_t const& at_right(right_t const& key) const {
    auto iter = find_right(key);
    if (iter == end_right()) {
      throw std::out_of_range("element with given key don't exist");
    }
    return *(iter.flip());
  }

  // Возвращает противоположный элемент по элементу
  // Если элемента не существует, добавляет его в bimap и на противоположную
  // сторону кладет дефолтный элемент, ссылку на который и возвращает
  // Если дефолтный элемент уже лежит в противоположной паре - должен поменять
  // соответствующий ему элемент на запрашиваемый (смотри тесты)
  template <typename = std::enable_if<std::is_default_constructible_v<left_t>>>
  right_t const& at_left_or_default(left_t const& key) {
    auto lit = find_left(key);
    if (lit != end_left()) {
      return *(lit.flip());
    }
    auto rit = find_right(right_t{});
    right_t r = right_t{};
    erase_right(r);
    return *(insert(key, r).flip());
  }

  template <typename = std::enable_if<std::is_default_constructible_v<right_t>>>
  left_t const& at_right_or_default(right_t const& key) {
    auto rit = find_right(key);
    if (rit != end_right()) {
      return *(rit.flip());
    }
    auto l = left_t{};
    erase_left(l);
    return *insert(l, key);
  }

  // lower и upper bound'ы по каждой стороне
  // Возвращают итераторы на соответствующие элементы
  // Смотри std::lower_bound, std::upper_bound.
  left_iterator lower_bound_left(const left_t& left) const {
    return left_iterator(left_map.lower(left));
  }
  left_iterator upper_bound_left(const left_t& left) const {
    return left_iterator(left_map.upper(left));
  }

  right_iterator lower_bound_right(const right_t& right) const {
    return right_iterator(right_map.lower(right));
  }
  right_iterator upper_bound_right(const right_t& right) const {
    return right_iterator(right_map.upper(right));
  }

  // Возващает итератор на минимальный по порядку left.
  left_iterator begin_left() const {
    return left_iterator(left_map.begin());
  }
  // Возващает итератор на следующий за последним по порядку left.
  left_iterator end_left() const {
    return left_iterator(left_map.end());
  }

  // Возващает итератор на минимальный по порядку right.
  right_iterator begin_right() const {
    return right_iterator(right_map.begin());
  }
  // Возващает итератор на следующий за последним по порядку right.
  right_iterator end_right() const {
    return right_iterator(right_map.end());
  }

  // Проверка на пустоту
  bool empty() const {
    return length == 0;
  }

  // Возвращает размер бимапы (кол-во пар)
  std::size_t size() const {
    return length;
  }

  // операторы сравнения
  friend bool operator==(bimap const& a, bimap const& b) {
    left_iterator ait = a.begin_left();
    left_iterator bit = b.begin_left();
    for (; ait != a.end_left(); ait++, bit++) {
      if (*ait != *bit || *(ait.flip()) != *(bit.flip())) {
        return false;
      }
    }
    return true;
  }
  friend bool operator!=(bimap const& a, bimap const& b) {
    return !(a == b);
  }

private:
  void clear() {
    if (size() != 0) {
      erase_left(begin_left(), end_left());
    }
  }
  std::pair<left_iterator, right_iterator> erase(left_iterator lit1,
                                                 right_iterator rit1) {
    left_iterator lit = lit1++;
    right_iterator rit = rit1++;
    length--;
    left_map.erase(lit.i);
    right_map.erase(rit.i);
    delete static_cast<element*>(static_cast<details::node<true>*>(lit.i));
    return {lit1, rit1};
  }

  // Вставка пары (left, right), возвращает итератор на left.
  // Если такой left или такой right уже присутствуют в bimap, вставка не
  // производится и возвращается end_left().
  template <typename LeftT = left_t, typename RightT = right_t>
  left_iterator insert_forward(LeftT&& left, RightT&& right) {
    if (find_left(left) == end_left() && find_right(right) == end_right()) {
      auto* elem =
          new element(std::forward<LeftT>(left), std::forward<RightT>(right));
      right_map.insert(elem);
      length++;
      return left_iterator(left_map.insert(elem));
    }
    return end_left();
  }
};
