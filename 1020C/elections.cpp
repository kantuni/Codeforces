#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> votes(m);
  vector<int> v(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> c[i];
    votes[v[i] - 1]++;
  }
  return 0;
}
