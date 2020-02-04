#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    vector<int> h(n, 0);
    int j = i;
    while (h[j] < 2) {
      h[j]++;
      j = p[j] - 1;
    }
    cout << j + 1 << " ";
  }
  cout << endl;
  return 0;
}
