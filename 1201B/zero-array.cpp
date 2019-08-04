// WA
#include <bits/stdc++.h>
using namespace std;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    pq.push(a);
  }
  bool possible = true;
  while (true) {
    auto first = pq.top(); pq.pop();
    auto second = pq.top(); pq.pop();
    if (first == 0 or second == 0) {
      possible = first == 0 and second == 0;
      break;
    }
    int common = min(first, second);
    pq.push(first - common);
    pq.push(second - common);
  }
  if (possible) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}