#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    freq[a[i].first]++;
  }
  sort(a.begin(), a.end());
  vector<int> color(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    color[a[i].second] = cur;
    cur = (cur + 1) % k;
  }
  bool ok = true;
  for (auto f: freq) {
    if (f.second > k) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << color[i] + 1 << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
