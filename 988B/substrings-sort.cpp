#include <bits/stdc++.h>
using namespace std;

int custom(string a, string b) {
  return a.size() < b.size();
}

bool solve(vector<string> vs) {
  bool ok = true;
  for (int i = 1; i < vs.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (vs[i].find(vs[j]) == string::npos) {
        ok = false;
        break;
      }
    }
  }
  return ok;
}

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
  }
  sort(vs.begin(), vs.end(), custom);
  bool ok = solve(vs);
  if (ok) {
    cout << "YES" << "\n";
    for (auto s: vs) {
      cout << s << "\n";
    }
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
