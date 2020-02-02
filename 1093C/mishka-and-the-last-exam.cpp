#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n / 2);
  for (int i = 0; i < n / 2; i++) {
    cin >> b[i];
  }
  long long l = -1, r = -1;
  for (int i = 0; i < n / 2; i++) {
    if (l == -1 and r == -1) {
      l = 0;
      r = b[i];
    } else if (b[i] - l > r) {
      l = b[i] - r;
    } else if (b[i] - l < r) {
      r = b[i] - l;
    }
    a[i] = l;
    a[n - i - 1] = r;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
