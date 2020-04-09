#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  long long p = k * (k - 1);
  if (n > p) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 1; i <= k and n > 0; i++) {
      for (int j = i + 1; j <= k and n > 0; j++) {
        cout << i << " " << j << endl;
        if (n > 1) {
          cout << j << " " << i << endl;
        }
        n -= 2;
      }
    }
  }
  return 0;
}
