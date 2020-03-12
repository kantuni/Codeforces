// MLE
#include <bits/stdc++.h>
#define INF (long long) 1e18
using namespace std;

int n, k;
vector<long long> a;
vector<vector<long long>> memo;

long long solve(int start, int cnt);
long long remember(int start, int cnt);

long long solve(int start, int cnt) {
  if (cnt == 1) {
    return a[n - 1] - a[start];
  }
  long long ans = INF;
  for (int i = start; i < n - 1; i++) {
    ans = min(ans, a[i] - a[start] + remember(i + 1, cnt - 1));
  }
  return ans;
}

long long remember(int start, int cnt) {
  if (memo[start][cnt] == INF) {
    memo[start][cnt] = solve(start, cnt);
  }
  return memo[start][cnt];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  a.resize(n);
  memo.resize(n, vector<long long>(k, INF));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = solve(0, k);
  cout << ans << endl;
  return 0;
}
