#pragma once
namespace details {
#include "node.h"

struct successor {
  using base_p = base_node*;
  static base_p minimum(base_p n) {
    if (n->left == nullptr) {
      return n;
    }
    return minimum(n->left);
  }

  static base_p next(base_p n) {
    if (n->right != nullptr) {
      return minimum(n->right);
    }
    while (n->parent != nullptr && n->parent->left != n) {
      n = n->parent;
    }
    return n->parent;
  }

  static base_p maximum(base_p n) {
    if (n->right == nullptr) {
      return n;
    }
    return maximum(n->right);
  }

  static base_p prev(base_p n) {
    if (n->left != nullptr) {
      return maximum(n->left);
    }
    while (n->parent != nullptr && n->parent->right != n) {
      n = n->parent;
    }
    return n->parent;
  }
};
template <class T, class K, bool isLeft, class Comparator>
struct map : Comparator {
private:
  using node_t = node<isLeft>;
  using node_p = node_t*;
  using base_t = base_node;
  using base_p = base_t*;
  base_t root;
  node_p base_to_node(base_node* b) const {
    return static_cast<node_p>(b);
  };
  const K& base_to_key(base_p n) const {
    return static_cast<node_key<K, isLeft>*>(base_to_node(n))->key;
  }
  const K& bi_to_key(T* n) const {
    return static_cast<node_key<K, isLeft>*>(n)->key;
  }

  const K& minimal_key() const {
    return base_to_key(root.right);
  }

  base_p node_to_base(node_p n) const {
    return static_cast<base_p>(static_cast<node_p>(n));
  }

  base_p T_to_base(T* t) {
    return node_to_base(static_cast<node_p>(t));
  }

  bool cmp_equal(const K& a, const K& b) const {
    return !cmp_less(a, b) && !cmp_less(b, a);
  }

  bool cmp_less(const K& a, const K& b) const {
    return Comparator::operator()(a, b);
  }

  base_p merge(base_p a, base_p b) {
    if (a == nullptr) {
      return b;
    }
    if (b == nullptr) {
      return a;
    }
    if (a->priority > b->priority) {
      a->right = merge(a->right, b);
      a->right->parent = a;
      return a;
    } else {
      b->left = merge(a, b->left);
      b->left->parent = b;
      return b;
    }
  }

  std::pair<base_p, base_p> split(base_p n, const K& key) {
    if (n == nullptr) {
      return {nullptr, nullptr};
    }
    if (cmp_less(key, base_to_key(n))) {
      auto t = split(n->left, key);
      n->left = t.second;
      if (n->left != nullptr) {
        n->left->parent = n;
      }
      return {t.first, n};

    } else {
      auto t = split(n->right, key);
      n->right = t.first;
      if (n->right != nullptr) {
        n->right->parent = n;
      }
      return {n, t.second};
    }
  }

  base_p search(base_p n, const K& key) const {
    while (n != nullptr) {
      if (cmp_equal(base_to_key(n), key)) {
        return n;
      } else if (cmp_less(base_to_key(n), key)) {
        n = n->right;
      } else {
        n = n->left;
      }
    }
    return const_cast<base_p>(&root);
  }

public:
  map(Comparator compare = Comparator(), base_p p = nullptr)
      : root(), Comparator(compare) {
    if (p != nullptr) {
      root.parent = p;
      p->parent = const_cast<base_p>(&root);
    }
  }
  map(base_p p) : root() {
    if (p != nullptr) {
      root.parent = p;
      p->parent = const_cast<base_p>(&root);
    }
  }

  base_p find(const K& key) const {
    return search(root.left, key);
  }

  base_p begin() const {
    return root.right;
  }
  base_p end() const {
    return const_cast<base_p>(&root);
  }

  base_p insert(T* n) {
    auto s = split(root.left, bi_to_key(n));
    base_p node = merge(s.first, node_to_base(n));
    root.left = merge(node, s.second);
    if (root.right == nullptr || cmp_less(bi_to_key(n), minimal_key())) {
      root.right = node_to_base(n);
    }
    root.left->parent = &root;
    return T_to_base(n);
  }

  void erase(base_p i) {
    if (cmp_equal(minimal_key(), base_to_key(i))) {
      if (successor::next(i) != &root) {
        root.right = successor::next(i);
      } else {
        root.right = nullptr;
      }
    }
    if (i->left != nullptr) {
      i->left->parent = nullptr;
    }
    if (i->right != nullptr) {
      i->right->parent = nullptr;
    }

    auto a = merge(i->left, i->right);
    if (a != nullptr) {
      a->parent = i->parent;
    }
    if (i->parent->left == i) {
      i->parent->left = a;

    } else {
      i->parent->right = a;
    }
    if (root.left != nullptr) {
      root.left->parent = &root;
    }
  }

  base_p lower(const K& key) const {
    base_p tmp = nullptr;
    auto n = root.left;
    while (n != nullptr) {
      if (!cmp_less(base_to_key(n), key)) {
        tmp = n;
        n = n->left;

      } else {
        n = n->right;
      }
    }
    if (tmp == nullptr) {
      return const_cast<base_p>(&root);
    }
    return tmp;
  }

  base_p upper(const K& key) const {
    base_p low = lower(key);
    if (low != end() && cmp_equal(key, base_to_key(low))) {
      return successor::next(low);
    }
    return low;
  }

  void swap(map& other) {
    std::swap(root.left->parent, other.root.left->parent);
    std::swap(root.parent, other.root.parent);
    std::swap(root.left, other.root.left);
    std::swap(root.right, other.root.right);
  }
};
} // namespace details
