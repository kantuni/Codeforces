#include <iostream>
#include <climits>
#include <vector>
using namespace std;

typedef vector<int> vi;

int solve(vi c) {
  int total = INT_MAX;
  for (int i = 0; i < c.size(); ++i) {
    // TODO:
    total = min(total, () * c[i] + solve(c);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  
  vi c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  
  cout << solve(c) << "\n";
  return 0;
}
