#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  vector<vector<int>> nums(k);
  vector<set<int>> sums(k);
  unordered_map<int, pair<int, int>> memo;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    nums[i].resize(n);
    int sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> nums[i][j];
      sum += nums[i][j];
    }
    for (int j = 0; j < n; j++) {
      int num = sum - nums[i][j];
      sums[i].insert(num);
      if (!memo.count(num)) {
        memo[num] = {i, j};
      } else {
        if (memo[num].first != i) {
          cout << "YES" << "\n";
          cout << memo[num].first + 1 << " ";
          cout << memo[num].second + 1 << "\n";
          cout << i + 1 << " " << j + 1 << "\n";
          return 0;
        }
      }
    }
  }
  cout << "NO" << "\n";
  return 0;
}
