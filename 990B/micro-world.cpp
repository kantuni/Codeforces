#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> memo;
  vector<int> uniq;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (memo[a] == 0) {
      uniq.push_back(a);
    }
    memo[a]++;
  }
  sort(uniq.begin(), uniq.end());
  int rm = 0;
  for (int i = 0; i < uniq.size() - 1; i++) {
    if (uniq[i + 1] - uniq[i] <= k) {
      rm += memo[uniq[i]];
    }
  }
  cout << n - rm << endl;
  return 0;
}
