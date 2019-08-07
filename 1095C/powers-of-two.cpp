#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  priority_queue<int> pq;
  int curr = n;
  while (curr > 0) {
    int p = log2(curr);
    curr -= pow(2, p);
    pq.push(p);
  }
  bool ok = k >= pq.size() and k <= n;
  if (ok) {
    k -= pq.size();
    while (k--) {
      int p = pq.top();
      pq.pop();
      pq.push(p - 1);
      pq.push(p - 1);
    }
  }
  if (ok) {
    cout << "YES" << endl;
    while (!pq.empty()) {
      cout << (int) pow(2, pq.top()) << " ";
      pq.pop();
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
