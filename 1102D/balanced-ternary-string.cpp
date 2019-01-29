#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> memo;
  int best = n / 3;
  for (int i = 0; i < n; i++) {
    memo[s[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (memo[s[i]] > best) {
      if (s[i] == '1') {
        if (memo['0'] < best) {
          memo[s[i]]--;
          s[i] = '0';
          memo[s[i]]++;
        }
      } else if (s[i] == '2') {
        if (memo['0'] < best or memo['1'] < best) {
          memo[s[i]]--;
          s[i] = memo['0'] < best ? '0' : '1';
          memo[s[i]]++;
        }
      }
    }
  }
  for (int i = n - 1; i > -1; i--) {
    if (memo[s[i]] > best) {
      if (s[i] == '0') {
        if (memo['1'] < best or memo['2'] < best) {
          memo[s[i]]--;
          s[i] = memo['2'] < best ? '2' : '1';
          memo[s[i]]++;
        }
      } else if (s[i] == '1') {
        if (memo['2'] < best) {
          memo[s[i]]--;
          s[i] = '2';
          memo[s[i]]++;
        }
      }
    }
  }
  cout << s << endl;
  return 0;
}
