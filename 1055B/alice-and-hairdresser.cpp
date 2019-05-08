#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int n, m, fn;
vector<int> a, t;

void build(int i, int L, int R) {
  if (L == R) {
    t[i] = a[L];
  } else {
    int M = (L + R) / 2;
    build(2 * i + 1, L, M);
    build(2 * i + 2, M + 1, R);
    t[i] = min(t[2 * i + 1], t[2 * i + 2]);
  }
}

void add(int i, int L, int R, int p, int d) {
  if (L == R) {
    a[p] += d;
    t[i] += d;
  } else {
    int M = (L + R) / 2;
    if (p <= M) {
      add(2 * i + 1, L, M, p, d);
    }
    if (p > M) {
      add(2 * i + 2, M + 1, R, p, d);
    }
    t[i] = min(t[2 * i + 1], t[2 * i + 2]);
  }
}

int rmq(int i, int L, int R, int l, int r) {
  if (r < L or R < l) {
    return INF;
  }
  if (l <= L and R <= r) {
    return t[i];
  }
  int M = (L + R) / 2;
  int r1 = rmq(2 * i + 1, L, M, l, r);
  int r2 = rmq(2 * i + 2, M + 1, R, l, r);
  return min(r1, r2);
}

int cut() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int s = i, e = n - 1;
    // TODO: binary search here
  }
  return 0;
}

int main() {
  cin >> n >> m >> fn;
  a.resize(n);
  t.resize(4 * n, INF);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, 0, n - 1);
  while (m--) {
    int T;
    cin >> T;
    if (T == 0) {
      cout << cut() << endl;
    } else {
      int p, d;
      cin >> p >> d;
      add(0, 0, n - 1, p - 1, d);
    }
  }
  return 0;
}
