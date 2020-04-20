#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int winner;
  if (k > n) {
    winner = *max_element(p.begin(), p.end());
  } else {
    queue<int> q;
    for (int i = 0 ; i < n; i++) {
      q.push(p[i]);
    }
    int wins = 0;
    winner = q.front();
    q.pop();
    while (wins != k) {
      int front = q.front();
      if (winner > front) {
        wins++;
        q.push(front);
        q.pop();
      } else {
        wins = 1;
        q.push(winner);
        winner = q.front();
        q.pop();
      }
    }
  }
  cout << winner << "\n";
  return 0;
}
