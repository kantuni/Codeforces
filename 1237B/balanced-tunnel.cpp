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
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  set<int> s;
  int i = n - 1, j = n - 1;
  while (i >= 0 and j >= 0) {
    if (s.count(b[j]) > 0) {
      j--;
    } else if (a[i] == b[j]) {
      i--, j--;
    } else {
      s.insert(a[i]);
      i--;
    }
  }
  cout << s.size() << endl;
  return 0;
}
