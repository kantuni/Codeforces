#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  unordered_map<string, int> windex;
  for (int i = 0; i < n; i++) {
    string w;
    cin >> w;
    windex[w] = i;
  }
  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  while (k--) {
    int x;
    cin >> x;
    vector<int> group(x);
    for (int i = 0; i < x; i++) {
      cin >> group[i];
      group[i]--;
    }
    int minc = 1e9;
    for (int i = 0; i < x; i++) {
      minc = min(minc, cost[group[i]]);
    }
    for (int i = 0; i < x; i++) {
      cost[group[i]] = minc;
    }
  }
  unsigned long long sum = 0;
  vector<string> words(m);
  for (int i = 0; i < m; i++) {
    cin >> words[i];
    sum += cost[windex[words[i]]];
  }
  cout << sum << "\n";
  return 0;
}
