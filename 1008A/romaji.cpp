#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  return c == 'a' or c == 'o' or c == 'u' or c == 'i' or c == 'e';
}

bool is_consonant(char c) {
  return !is_vowel(c);
}

int main() {
  string s;
  cin >> s;
  char last = s[s.size() - 1];
  if (is_consonant(last) and last != 'n') {
    cout << "NO" << "\n";
    return 0;
  }
  bool ok = true;
  for (int i = 0; ok and i < s.size() - 1; i++) {
    if (s[i] != 'n' and is_consonant(s[i]) and is_consonant(s[i + 1])) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
