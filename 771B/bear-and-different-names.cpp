#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<string> s(n - k + 1);
  for (int i = 0; i < s.size(); i++) {
    cin >> s[i];
  }
  vector<string> names(n);
  for (int i = 0; i < n; i++) {
    names[i] = 'A' + (i % 26);
    for (int j = 0; j < i / 26; j++) {
      names[i] += 'a';
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == "NO") {
      names[i + k - 1] = names[i];
    }
  }
  for (auto name: names) {
    cout << name << " ";
  }
  cout << endl;
  return 0;
}
