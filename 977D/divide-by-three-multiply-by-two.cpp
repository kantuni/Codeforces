#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<long long> memo;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    set<long long> temp = memo;
    stack<long long> s;
    s.push(a[i]);
    int count = 1;
    bool works = true;
    while (count < n) {
      long long top = s.top();
      if (top % 3 == 0 and temp.count(top / 3)) {
        s.push(top / 3);
        count++;
      } else if (temp.count(top * 2)) {
        s.push(top * 2);
        count++;
      } else {
        works = false;
        break;
      }
    }
    if (works) {
      vector<long long> ans;
      while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
      }
      for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
      }
      cout << endl;
      break;
    }
  }
  return 0;
}
