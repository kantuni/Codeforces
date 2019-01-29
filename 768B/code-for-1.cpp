#include <bits/stdc++.h>
using namespace std;

vector<long long> generate(long long n) {
  if (n < 2) return {n};
  vector<long long> all;
  vector<long long> floor = generate(n / 2);
  all.insert(all.end(), floor.begin(), floor.end());
  all.push_back(n % 2);
  all.insert(all.end(), floor.begin(), floor.end());
  return all;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, l, r;
  cin >> n >> l >> r;
  vector<long long> list = generate(n);
  long long ans = 0;
  for (int i = l - 1; i < r; i++) {
    ans += list[i];
  }
  cout << ans << endl;
  return 0;
}
