#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long s;
  cin >> n >> s;
  vector<int> v(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  int ans = -1;
  if (sum >= s) {  
    sort(v.begin(), v.end());
    long long tmp = 0; 
    for (int i = 1; i < n; i++) {
      int diff = v[i] - v[0];
      tmp += diff;
    }
    if (tmp < s) {
      int cnt = ceil(1.0 * (s - tmp) / n);
      ans = v[0] - cnt;
    } else {
      ans = v[0];
    }
  }
  cout << ans << endl;
  return 0;
}
