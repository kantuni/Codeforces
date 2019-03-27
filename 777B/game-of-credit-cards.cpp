#include <bits/stdc++.h>
using namespace std;

int mf(string s, string m) {
  int cnt = 0;
  for (auto num: s) {
    auto lower = lower_bound(m.begin(), m.end(), num);
    if (lower != m.end()) {
      m.erase(lower);
      cnt++;
    }
  }
  return s.size() - cnt;
}

int sf(string s, string m) {
  int cnt = 0;
  for (auto num: s) {
    auto upper = upper_bound(m.begin(), m.end(), num);
    if (upper != m.end()) {
      m.erase(upper);
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  string s, m;
  cin >> s >> m;
  sort(s.begin(), s.end());
  sort(m.begin(), m.end());
  cout << mf(s, m) << endl;
  cout << sf(s, m) << endl;
  return 0;
}
