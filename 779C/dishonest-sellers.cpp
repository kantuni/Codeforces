#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<pair<int, int>> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = {a[i] - b[i], i};
  }
  sort(diff.begin(), diff.end());
  int total = 0;
  int i = 0, min_index;
  while (k--) {
    min_index = diff[i].second;
    total += a[min_index];
    a[min_index] = 0;
    b[min_index] = 0;
    i++;
  }
  while (i < n and diff[i].first < 0) {
    min_index = diff[i].second;
    total += a[min_index];
    a[min_index] = 0;
    b[min_index] = 0;
    i++;   
  }
  for (auto value : b) {
    total += value;
  }
  cout << total << endl;
  return 0;
}
