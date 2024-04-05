#include <bits/stdc++.h>
using namespace std;

vector<int> to_digits(long long num) {
  vector<int> digits;
  while (num > 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  reverse(digits.begin(), digits.end());
  return digits;
}

long long to_number(vector<int>& digits) {
  long long num = 0;
  for (auto d: digits) {
    num = (num * 10) + d;
  }
  return num;
}

int maximize(vector<int>& digits, int i) {
  digits[i]--;
  for (int j = i + 1; j < digits.size(); j++) {
    digits[j] = 9;
  }
  return accumulate(digits.begin(), digits.end(), 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x;
  cin >> x;
  vector<int> xd = to_digits(x);
  int mx = accumulate(xd.begin(), xd.end(), 0);
  long long ans = x;
  for (int i = 0; i < xd.size(); i++) {
    vector<int> xdi(xd);
    int mxi = maximize(xdi, i); 
    bool better = mxi > mx or (mxi == mx and to_number(xdi) > ans);
    if (better) {
      mx = mxi;
      ans = to_number(xdi);
    }
  }
  cout << ans << "\n";
  return 0;
}
