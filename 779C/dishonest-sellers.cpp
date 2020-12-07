#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

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
  vii diff;
  for (int i = 0; i < n; i++) {
    ii d = {a[i] - b[i], i};
    diff.push_back(d);
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
