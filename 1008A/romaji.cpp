#include <bits/stdc++.h>
using namespace std;

bool isConsonant(char c) {
  return c != 'a' and c != 'o' and c != 'u' and c != 'i' and c != 'e';
}

int main() {
  string s;
  cin >> s;
  char last = s.back();
  if (isConsonant(last) and last != 'n') {
    cout << "NO" << endl;
    return 0;
  }
  bool ok = true;
  for (int i = 0; ok and i < s.size() - 1; i++) {
    if (s[i] != 'n' and isConsonant(s[i]) and isConsonant(s[i + 1])) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
