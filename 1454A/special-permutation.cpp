#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = n - i;
    }
    swap(p[n / 2], p[n - 1]);
    for (int i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
