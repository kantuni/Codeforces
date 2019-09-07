#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> zbefore(n);
    int z = 0;
    for (int i = 0; i < n; i++) {
      zbefore[i] = z;
      z = s[i] == '0' ? z + 1 : 0;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        long long num = 0;
        int j = i;
        while (j < n) {
          num = 2 * num + (s[j] - '0');
          if (j - i + 1 + zbefore[i] < num) {
            break;
          }
          ans++;
          j++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
