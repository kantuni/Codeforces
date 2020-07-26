// WA
#include <bits/stdc++.h>
using namespace std;

int n, I;
vector<int> a;
map<int, int> freq;

bool possible(int K) {
  int k = ceil(log2(1.0 * K));
  return n * k <= 8 * I;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> I;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
  set<int> s(a.begin(), a.end());
  a.assign(s.begin(), s.end());
  long long ans = 0;
  int l = 0, r = a.size() - 1;
  while (l <= r) {
    if (possible(r - l + 1)) {
      break;
    }
    int fl = freq[a[l]];
    int fr = freq[a[r]];
    if (fl < fr) {
      ans += fl;
      l++;
    } else {
      ans += fr;
      r--;
    }
  }
  cout << ans << endl;
  return 0;
}
