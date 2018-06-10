// TLE
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int x, y, size;
  Node *left, *right;

  Node(int x) {
    this->x = x;
    this->y = rand();
    this->size = 1;
    this->left = this->right = NULL;
  }
};

struct Treap {
  Node *root;

  public:
    Treap() { this->root = NULL; }
    int size(Node* node) { return (node != NULL) ? node->size : 0; }
    void insert(int x) { insert(this->root, x); }
    int smaller(int x) { return smaller(this->root, x); }

  private:
    void insert(Node* &node, int x) {
      if (node == NULL) {
        node = new Node(x);
        return;
      }
      node->size += 1;
      if (x < node->x) {
        insert(node->left, x);
        if (node->y < node->left->y) {
          node = rr(node);
        }
      } else {
        insert(node->right, x);
        if (node->y < node->right->y) {
          node = lr(node);
        }
      }
    }

    Node* lr(Node* node) {
      Node *r = node->right, *rl = r->left;
      swap(node->size, r->size);
      node->size += size(node->left) - size(r->right);
      r->left = node;
      node->right = rl;
      return r;
    }

    Node* rr(Node* node) {
      Node *l = node->left, *lr = l->right;
      swap(node->size, l->size);
      node->size += size(node->right) - size(l->left);
      l->right = node;
      node->left = lr;
      return l;
    }

    int smaller(Node *node, int x) {
      if (node == NULL) {
        return 0;
      } else if (x == node->x) {
        return smaller(node->left, x);
      } else if (x < node->x) {
        return smaller(node->left, x);
      } else {
        return size(node->left) + 1 + smaller(node->right, x);
      }
    }
};

int main() {
  int n, k;
  cin >> n >> k;
  Treap *treap = new Treap();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    treap->insert(a[i]);
  }
  sort(a.begin(), a.end());
  vector<int> color(n, 1);
  for (int i = 1; i < n; i++) {
    if (a[i - 1] == a[i] or color[i] == 0) {
      continue;
    }
    int c1 = treap->smaller(a[i]);
    int c2 = treap->smaller(a[i] - k);
    int cnt = c1 - c2;
    for (int j = i - 1; cnt > 0; j--) {
      color[j] = 0;
      cnt--;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += color[i];
  }
  cout << ans << "\n";
  return 0;
}
