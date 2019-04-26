#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int n, m, l;
vector<int> a;
vector<pair<int, int>> t;

void build(int i, int L, int R) {
  if (L == R) {
    t[i] = {a[L], a[R]};
  } else {
    int M = (L + R) / 2;
    build(2 * i + 1, L, M);
    build(2 * i + 2, M + 1, R);
    t[i] = {
      min(t[2 * i + 1].first, t[2 * i + 2].first),
      max(t[2 * i + 1].second, t[2 * i + 2].second)
    };
  }
}

void add(int i, int L, int R, int p, int d) {
  if (L == R) {
    a[p] += d;
    t[i].first += d;
    t[i].second += d;
  } else {
    int M = (L + R) / 2;
    if (p <= M) {
      add(2 * i + 1, L, M, p, d);
    }
    if (p > M) {
      add(2 * i + 2, M + 1, R, p, d);
    }
    t[i] = {
      min(t[2 * i + 1].first, t[2 * i + 2].first),
      max(t[2 * i + 1].second, t[2 * i + 2].second)
    };
  }
}

int cut(int i, int L, int R) {
  auto [mn, mx] = t[i];
  if (mx <= l) return 0;
  if (mn > l) return 1;
  int M = (L + R) / 2;
  int c1 = cut(2 * i + 1, L, M);
  int c2 = cut(2 * i + 2, M + 1, R);
  return c1 + c2;
}

int main() {
  cin >> n >> m >> l;
  a.resize(n);
  t.resize(4 * n, {INF, 0});
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, 0, n - 1);
  while (m--) {
    int t;
    cin >> t;
    if (t == 0) {
      cout << cut(0, 0, n - 1) << endl;
    } else {
      int p, d;
      cin >> p >> d;
      add(0, 0, n - 1, p - 1, d);
      for (auto ai: a) {
        cout << ai << " ";
      }
      cout << endl
    }
  }
  return 0;
}
