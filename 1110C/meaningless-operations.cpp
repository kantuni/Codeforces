#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

vector<int> to_binary(int n) {
  vector<int> bin;
  while (n > 0) {
    bin.push_back(n % 2);
    n /= 2;
  }
  reverse(bin.begin(), bin.end());
  return bin;
}

int solve(int n) {
  vector<int> a = to_binary(n);
  int fone = -1;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 1) {
      fone = i;
      break;
    }
  }
  vector<int> b(a);
  int ones = 0;
  for (int i = 0; i < b.size(); i++) {
    if (i < fone) {
      b[i] = 0;
      continue;
    }
    b[i] = !a[i];
    ones += !a[i];
  }
  if (ones == 0) {
    int ld = 1;
    for (int i = sqrt(n); i > 1; i--) {
      if (n % i == 0) {
        ld = max(i, n / i);
      }
    }
    b = to_binary(ld);
  }
  int m = 0;
  for (int i = b.size() - 1; i > -1; i--) {
    m += b[i] * pow(2, b.size() - 1 - i);
  }
  return gcd(n ^ m, n & m);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  vector<long long> a(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i];
  }
  for (auto val: a) {
    cout << solve(val) << endl;
  }
  return 0;
}
