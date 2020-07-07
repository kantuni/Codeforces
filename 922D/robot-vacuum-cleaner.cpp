// WA
#include <bits/stdc++.h>
using namespace std;

int noise(string t) {
  int cnt = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 's') {
      for (int j = i + 1; j < t.size(); j++) {
        if (t[j] == 'h') {
          cnt++;
        }
      }
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<string> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  vector<string> onlys;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < t[i].size(); j++) {
      if (t[i][j] == 'h') {
        ok = false;
        break;
      }
    }
    if (ok) {
      onlys.push_back(t[i]);
    }
  }
  vector<string> onlyh;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < t[i].size(); j++) {
      if (t[i][j] == 's') {
        ok = false;
        break;
      }
    }
    if (ok) {
      onlyh.push_back(t[i]);
    }
  }
  deque<string> dq;
  for (int i = 0; i < n; i++) {
    bool sonly = true;
    for (int j = 0; j < t[i].size(); j++) {
      if (t[i][j] == 'h') {
        sonly = false;
        break;
      }
    }
    bool honly = true;
    for (int j = 0; j < t[i].size(); j++) {
      if (t[i][j] == 's') {
        honly = false;
        break;
      }
    }
    if (!sonly and !honly) {
      if (t[i][0] == 's') {
        dq.push_front(t[i]);
      } else {
        dq.push_back(t[i]);
      }
    }
  }
  string ts;
  for (auto s: onlys) {
    ts += s;
  }
  for (auto s: dq) {
    ts += s;
  }
  for (auto s: onlyh) {
    ts += s;
  }
  cout << noise(ts) << endl;
  return 0;
}
