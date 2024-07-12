#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> memo;

// Arguments should be sorted (i.e. a <= b <= c)
bool exists(int a, int b, int c) {
  if (a == b and b == c) {
    return memo.count(a) and memo[a].size() > 2;
  }
  if (a == b) {
    return memo.count(a) and memo[a].size() > 1 and memo.count(c);
  }
  if (b == c) {
    return memo.count(a) and memo.count(b) and memo[b].size() > 1;
  }
  return memo.count(a) and memo.count(b) and memo.count(c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      memo[a[i] % 10].push_back(i);
    }
    bool ok = (
      // 3
      exists(0, 0, 3) or
      exists(0, 1, 2) or
      exists(1, 1, 1) or
      // 13
      exists(0, 4, 9) or
      exists(0, 5, 8) or
      exists(0, 6, 7) or
      exists(1, 3, 9) or
      exists(1, 4, 8) or
      exists(1, 5, 7) or
      exists(1, 6, 6) or
      exists(2, 2, 9) or
      exists(2, 3, 8) or
      exists(2, 4, 7) or
      exists(2, 5, 6) or
      exists(3, 3, 7) or
      exists(3, 4, 6) or
      exists(3, 5, 5) or
      exists(4, 4, 5) or
      // 23
      exists(5, 9, 9) or
      exists(6, 8, 9) or
      exists(7, 7, 9) or
      exists(7, 8, 8)
    );
    if (ok) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
    memo.clear();
  }
  return 0;
}
