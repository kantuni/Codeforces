// WA
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long s, i, e;
    cin >> s >> i >> e;
    long long ans = 0;
    if (s + e > i) {
      long long diff = s + e - i;
      ans = diff / 2 + (diff % 2 == 1);
    }
    cout << min(ans, max(s > i ? 1LL : 0LL, e)) << endl;
  }
  return 0;
}