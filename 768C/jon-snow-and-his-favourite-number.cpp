// TLE
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  int a;
  vector<int> strengths(n);
  for (int i = 0; i < n; ++i) {
    cin >> strengths[i];
  }
  for (int i = 0; i < k; ++i) {
    sort(begin(strengths), end(strengths));
    for (int j = 0; j < strengths.size(); ++j) {
      if (j % 2 == 0) {
        strengths[j] ^= x;
      }
    }
  }
  int min, max;
  min = max = strengths[0];
  for (int i = 0; i < strengths.size(); ++i) {
    if (min > strengths[i]) {
      min = strengths[i];
    }

    if (max < strengths[i]) {
      max = strengths[i];
    }
  }
  cout << max << " " << min << endl;
  return 0;
}
