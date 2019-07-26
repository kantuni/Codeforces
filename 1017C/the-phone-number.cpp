// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = n / 2; i < n; i++) {
    a.push_back(i + 1);
  }
  for (int i = 0; i < n / 2; i++) {
    a.push_back(i + 1);
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == n) {
      swap(a[i], a[i + 1]);
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
