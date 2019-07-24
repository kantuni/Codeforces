#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k, s;
  cin >> n >> k >> s;
  if (k * (n - 1) < s) {
    cout << "NO" << endl;
    return 0;
  }
  if (s < k) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  long long q = s / k;
  long long r = s % k;
  long long curr = 1;
  for (int i = 0; i < k; i++) {
    int step = q;
    if (r > 0) {
      step++;
      r--;
    }
    if (i % 2 == 0) {
      curr += step;
    } else {
      curr -= step;
    }
    cout << curr << " ";
  }
  cout << endl;
  return 0;
}
