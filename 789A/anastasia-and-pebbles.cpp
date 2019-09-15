#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    pq.push(w);
  }
  long long ans = 0;
  while (!pq.empty()) {
    int w = pq.top();
    pq.pop();
    if (w > 2 * k) {
      ans += w / (2 * k);
      w = w % (2 * k);
    } else if (w > k and w <= 2 * k) {
      w = 0;
      ans++;
    } else {
      if (!pq.empty()) {
        w = pq.top();
        pq.pop();
      }
      w = max(w - k, 0);
      ans++;
    }
    if (w > 0) {
      pq.push(w);
    }
  }
  cout << ans << endl;
  return 0;
}
