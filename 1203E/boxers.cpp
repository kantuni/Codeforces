#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  set<int> s;
  for (int i = 0; i < n; i++) {
    int old = s.size();
    if (a[i] - 1 > 0) {
      s.insert(a[i] - 1);
    }
    if (s.size() == old) {
      s.insert(a[i]);
    }
    if (s.size() == old) {
      s.insert(a[i] + 1);
    }
  }
  cout << s.size() << endl;
  return 0;
}
