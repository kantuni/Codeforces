#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  vector<int> clt = {0};
  int total = a[0];
  for (int i = 1; total <= sum / 2 and i < n; i++) {
    if (a[0] / 2 >= a[i]) {
      clt.push_back(i);
      total += a[i]; 
    }
  }
  if (total > sum / 2) {
    cout << clt.size() << endl;
    for (auto id: clt) {
      cout << id + 1 << " ";
    }
    cout << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
