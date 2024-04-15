#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
  return find(vowels.begin(), vowels.end(), c) != vowels.end();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<char, int>> lcs;
  for (int i = 0; i < n; i++) {
    if (lcs.size() > 0 and lcs.back().first == s[i]) {
      auto [letter, count] = lcs.back();
      lcs.pop_back();
      lcs.push_back({letter, count + 1});
    } else {
      lcs.push_back({s[i], 1});
    }
  }
  string ans;
  for (auto [letter, count]: lcs) {
    if (letter == 'e' or letter == 'o') {
      ans += string(count == 2 ? 2 : 1, letter);
    } else if (is_vowel(letter)) {
      ans += string(1, letter);
    } else {
      ans += string(count, letter);
    }
  }
  cout << ans << "\n";
  return 0;
}
