#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  multiset<int, greater<int>> ms(a.begin(), a.end());
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    sum -= a[i];
    auto it = ms.find(a[i]);
    if (it != ms.end()) {
      ms.erase(it);
    }
    int m = *ms.begin();
    if (sum - m == m) {
      ans.push_back(i + 1);    
    }
    sum += a[i];
    ms.insert(a[i]);
  }
  cout << ans.size() << endl;
  for (auto id: ans) {
    cout << id << " ";
  }
  cout << endl;
  return 0;
}
