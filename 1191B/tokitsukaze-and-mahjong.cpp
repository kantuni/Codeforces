#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> m, p, s;
  for (int i = 0; i < 3; i++) {
    string tile;
    cin >> tile;
    if (tile[1] == 'm') {
      m.push_back(tile[0] - '0');
    } else if (tile[1] == 'p') {
      p.push_back(tile[0] - '0');
    } else {
      s.push_back(tile[0] - '0');
    }
  }
  sort(m.begin(), m.end());
  sort(p.begin(), p.end());
  sort(s.begin(), s.end());
  bool meld = false;
  if (m.size() == 3) {
    bool same = m[0] == m[1] and m[1] == m[2];
    bool seq = m[1] - m[0] == 1 and m[2] - m[1] == 1;
    meld = same or seq;
  } else if (p.size() == 3) {
    bool same = p[0] == p[1] and p[1] == p[2];
    bool seq = p[1] - p[0] == 1 and p[2] - p[1] == 1;
    meld = same or seq;
  } else if (s.size() == 3) {
    bool same = s[0] == s[1] and s[1] == s[2];
    bool seq = s[1] - s[0] == 1 and s[2] - s[1] == 1;
    meld = same or seq;
  }
  bool one = false;
  if (m.size() > 1) {
    for (int i = 0; i < m.size() - 1; i++) {
      one = one or m[i + 1] - m[i] <= 2;
    }
  }
  if (p.size() > 1) {
    for (int i = 0; i < p.size() - 1; i++) {
      one = one or p[i + 1] - p[i] <= 2;
    }
  }
  if (s.size() > 1) {
    for (int i = 0; i < s.size() - 1; i++) {
      one = one or s[i + 1] - s[i] <= 2;
    }
  }
  int ans = (meld) ? 0 : (one) ? 1 : 2;
  cout << ans << endl;
  return 0;
}
