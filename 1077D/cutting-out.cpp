#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  map<int, int> memo;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    memo[s[i]]++;
  }
  multimap<int, int, greater<int>> rmemo;
  for (auto m: memo) {
    rmemo.insert(make_pair(m.second, m.first));
  }
  long long sum = 0, mx = 0;
  int kc = k;
  for (auto m: rmemo) {
    if (kc == 0) {
      break;
    }
    sum += m.first;
    if (min(sum / k, (long long) m.first) > mx) {
      mx = min(sum / k, (long long) m.first);
    }
    kc--;
  }
  vector<int> t;
  for (auto m: rmemo) {
    int cnt = m.first / mx;
    for (int i = 0; i < cnt and t.size() < k; i++) {
      t.push_back(m.second);
    }
  }
  for (int i = 0; i < k; i++) {
    cout << t[i] << " ";
  }
  cout << endl;
  return 0;
}
