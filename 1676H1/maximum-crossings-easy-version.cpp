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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ordered_set<pair<int, int>> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int k = s.order_of_key({a[i], INT_MIN});
      ans += s.size() - k;
      s.insert({a[i], i});
    }
    cout << ans << "\n";
  }
  return 0;
}
