#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a;
  cin >> n >> a;
  vector<tuple<double, int, int, int>> angles;
  for (int i = 0; i < n - 2; i++) {
    double alpha = (180.0 / n) * (i + 1);
    angles.push_back({alpha, 2, 1, i + 3}); 
  }
  tuple<int, int, int> ans;
  double best = 180;
  for (auto [alpha, x, y, z]: angles) {
    if (abs(alpha - a) < best) {
      best = abs(alpha - a);
      ans = {x, y, z};
    }
  }
  auto [x, y, z] = ans;
  cout << x << " " << y << " " << z << "\n";
  return 0;
}
