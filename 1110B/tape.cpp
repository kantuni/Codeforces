#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long ans = n;
  priority_queue<long long> pq;
  for (int i = 1; i < n; i++) {
    long long diff = b[i] - b[i - 1] + 1;
    pq.push(-diff);
  }
  long long used = n;
  while (used > k) {
    long long diff = -pq.top(); pq.pop();
    ans = ans - 2 + diff;
    used--;
  }
  cout << ans << endl;
  return 0;
}
