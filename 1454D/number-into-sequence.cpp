#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
  vector<int> p(n + 1, 1);
  p[0] = p[1] = 0;
  for (int i = 2; i * i < p.size(); i++) {
    if (p[i] == 0) {
      continue;
    }
    for (int j = 0; i * i + i * j < p.size(); j++) {
      p[i * i + i * j] = 0;
    }
  }
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> ps = sieve(sqrt(n) + 1);
    vector<long long> ans = {n};
    for (int i = 0; i < ps.size(); i++) {
      if (ps[i] == 0) {
        continue;
      }
      vector<long long> tmp;
      long long nc = n;
      while (nc % i == 0) {
        long long nxt = nc / i;
        if (nxt % i > 0) {
          break;
        }
        tmp.push_back(i);
        nc = nxt;
      }
      tmp.push_back(nc);
      if (tmp.size() > ans.size()) {
        ans = tmp;
      }
    }
    cout << ans.size() << endl;
    for (auto val: ans) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
