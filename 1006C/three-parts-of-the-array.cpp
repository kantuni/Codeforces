#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  if (n == 1) {
    cout << 0 << endl;
  } else {
    long long s1 = 0, s3 = 0;
    long long ans = 0;
    int i = 0, j = n - 1;
    s1 += d[i];
    s3 += d[j];
    while (i < j) {
      if (s1 == s3) {
        ans = max(ans, s1);
        i++, j--;
        s1 += d[i];
        s3 += d[j];
      } else if (s1 < s3) {
        i++;
        s1 += d[i];
      } else {
        j--;
        s3 += d[j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
