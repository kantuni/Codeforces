#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(101, 0);
  set<int> s;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
    cnt[a]++;
  }
  vector<int> sv(s.begin(), s.end());
  if (sv.size() == 2 and cnt[sv[0]] == cnt[sv[1]]) {
    cout << "YES" << endl;
    cout << sv[0] << " " << sv[1] << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
