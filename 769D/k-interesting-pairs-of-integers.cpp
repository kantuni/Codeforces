#include <bits/stdc++.h>
#define N 14
using namespace std;

vector<int> freq(20001);

long long helper(int x, int k, int i, vector<int>& res) {
  if (k == 0) {
    if (freq[x] > 0) {
      res.push_back(x);
    }
    return freq[x];
  }
  if (i == N) {
    return 0;
  }
  if (N - i < k) {
    return 0;
  }
  long long c1 = helper(x, k, i + 1, res);
  long long c2 = helper(x ^ (1 << i), k - 1, i + 1, res); 
  return c1 + c2;
}

long long interesting(int x, int k) {
  vector<int> res;
  return helper(x, k, 0, res);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  set<int> uniq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
    uniq.insert(a[i]);
  }
  long long ans = 0;
  for (auto num: uniq) {
    long long cnt = interesting(num, k);
    if (k == 0) {
      ans += cnt * (cnt - 1);
    } else {
      ans += cnt * freq[num];
    }
  }
  cout << ans / 2 << "\n";
  return 0;
}
