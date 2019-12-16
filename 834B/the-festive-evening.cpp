#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 26) {
    cout << "NO" << endl;
    return 0;
  }
  vector<int> letters(26, 0);
  vector<int> seen(26, 0);
  bool unguarded = false;
  for (int i = 0; i < s.size(); i++) {
    int index = s[i] - 65;
    letters[index]++;
  }
  for (int i = 0; i < s.size(); i++) {
    char index = s[i] - 65;
    if (seen[index] == 0) {
      k--;
    }
    seen[index]++;
    if (k < 0) {
      unguarded = true;
      break;
    }
    if (letters[index] == seen[index]) {
      k++;
    }
  }
  if (unguarded) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
