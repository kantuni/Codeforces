#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> ss(n);
    map<string, ordered_set<int>> pos;
    for (int i = 0; i < n; i++) {
      cin >> ss[i];
      pos[ss[i]].insert(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      string s = ss[i];
      // differ in the first character
      for (char first = 'a'; first <= 'k'; first++) {
        if (s[0] == first) {
          continue;
        }
        char second = s[1];
        string ns = string(1, first) + string(1, second);
        if (pos.count(ns) > 0) {
          int upper = pos[ns].order_of_key(i);
          ans += pos[ns].size() - upper;
        }
      }
      // differ in the second character
      for (char second = 'a'; second <= 'k'; second++) {
        if (s[1] == second) {
          continue;
        }
        char first = s[0];
        string ns = string(1, first) + string(1, second);
        if (pos.count(ns) > 0) {
          int upper = pos[ns].order_of_key(i);
          ans += pos[ns].size() - upper;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
