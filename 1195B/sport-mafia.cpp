#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long l = 0, h = n;
  while (l < h) {
    long long m = (l + h) / 2;
    long long candies = m * (m + 1) / 2;
    if (candies + m < k + n) {
      l = m + 1;
    } else {
      h = m;
    }
  }
  cout << n - l << endl;
  return 0;
}
