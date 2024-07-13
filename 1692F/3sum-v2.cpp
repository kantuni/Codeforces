#include <bits/stdc++.h>
using namespace std;

vector<int> memo(10);

// Arguments should be sorted (i.e. a <= b <= c)
bool exists(int a, int b, int c) {
  if (a == b and b == c) {
    return memo[a] > 2;
  }
  if (a == b) {
    return memo[a] > 1 and memo[c];
  }
  if (b == c) {
    return memo[a] and memo[b] > 1;
  }
  return memo[a] and memo[b] and memo[c];
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
      memo[a[i] % 10]++;
    }
    bool ok = false;
    for (int a = 0; a < 10; a++) {
      for (int b = a; b < 10; b++) {
        for (int c = b; c < 10; c++) {
          int s = a + b + c;
          if (s % 10 == 3 and exists(a, b, c)) {
            ok = true;
            break;
          }
        }
      }
    }
    if (ok) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
    memo.assign(10, 0);
  }
  return 0;
}
