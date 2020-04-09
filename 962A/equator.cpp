#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    cur += a[i];
    if (cur >= ceil(sum / 2.0)) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}
