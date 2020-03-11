#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> r;
    long long tmp = 0;
    int i = 0;
    while (i < n - 1 and r.size() < k - 1) {
      tmp += a[i];
      if (tmp % 2 == 1) {
        r.push_back(i);
        tmp = 0;
      }
      i++;
    }
    for (int j = i; j < n; j++) {
      tmp += a[j];
    }
    if (r.size() == k - 1 and tmp % 2 == 1) {
      r.push_back(n - 1);
      cout << "YES" << endl;
      for (auto ri: r) {
        cout << ri + 1 << " ";
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
