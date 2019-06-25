// WA
#include <bits/stdc++.h>
using namespace std;

bool prefix(string s, string t) {
  for (int i = 0; i < t.size(); i++) {
    if (s[i] != t[i]) {
      return false;
    }
  }
  return true;
}

bool suffix(string s, string t) {
  for (int i = t.size() - 1, j = s.size() - 1; i > -1; i--, j--) {
    if (s[j] != t[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<string> ps(2 * n - 2);
  string original;
  for (int i = 0; i < 2 * n - 2; i++) {
    cin >> ps[i];
    if (ps[i].size() == n - 1) {
      original += original.size() == 0 ? ps[i] : ps[i].substr(n - 2);
    }
  }
  string ans(2 * n - 2, ' ');
  for (int k = 1; k < n; k++) {
    int s1, s2;
    for (int i = 0; i < ps.size(); i++) {
      if (ps[i].size() == k) {
        s1 = i;
        break;
      }
    }
    for (int i = s1 + 1; i < ps.size(); i++) {
      if (ps[i].size() == k) {
        s2 = i;
        break;
      }
    }
    string first = ps[s1];
    string second = ps[s2];
    if (prefix(original, first)) {
      if (suffix(original, second) {
        ans[s1] = 'P';
        ans[s2] = 'S';
      } else {
        ans[s1] = 'S';
        ans[s2] = 'P';
      }
    } else {
      ans[s1] = 'S';
      ans[s2] = 'P';
    }
  }
  cout << ans << endl;
  return 0;
}
