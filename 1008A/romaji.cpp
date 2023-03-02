#include <bits/stdc++.h>
using namespace std;

bool is_consonant(char c) {
  return c != 'a' and c != 'o' and c != 'u' and c != 'i' and c != 'e';
}

int main() {
  string s;
  cin >> s;
  char last = s.back();
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
