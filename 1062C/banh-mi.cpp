// WA
#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> tree;

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = a[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);
    tree[node] = 
      tree[2 * node + 1] + tree[2 * node + 2] + 
      max(tree[2 * node + 1], tree[2 * node + 2]);
  }
}

int query(int node, int start, int end, int l, int r) {
  if (r < start or end < l) {
    return 0;
  }
  if (l <= start and end <= r) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  int p1 = query(2 * node + 1, start, mid, l, r);
  int p2 = query(2 * node + 2, mid + 1, end, l, r);
  return p1 + p2;
}

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }
  tree.resize(2 * n - 1);
  build(0, 0, n - 1);
  for (int i = 0; i < tree.size(); i++) {
    cout << tree[i] << " ";
  }
  cout << endl;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(0, 0, n - 1, l - 1, r - 1) << endl;
  }
  return 0;
}
