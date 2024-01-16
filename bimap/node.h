#pragma once
inline std::mt19937 e(std::random_device{}());
struct base_node {
  base_node* parent{nullptr};
  base_node* left{nullptr};
  base_node* right{nullptr};
  std::size_t priority = e();
};
template <bool isLeft>
struct node : base_node {};

template <class K, bool isLeft>
struct node_key : node<isLeft> {
  const K key;
  node_key(K&& k) : key(std::move(k)) {}

  node_key(const K& k) : key(k) {}
};

template <class L, class R>
struct bi_node : public node_key<L, true>, public node_key<R, false> {
  using left_n = node_key<L, true>;
  using right_n = node_key<R, false>;

  bi_node(L&& left, R&& right)
      : left_n(std::move(left)), right_n(std::move(right)) {}
  bi_node(const L& left, const R& right) : left_n(left), right_n(right) {}
  bi_node(const L& left, R&& right) : left_n(left), right_n(std::move(right)) {}
  bi_node(L&& left, const R& right) : left_n(std::move(left)), right_n(right) {}
};