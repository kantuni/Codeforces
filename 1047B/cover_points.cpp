// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  pair<int, int> mx, my;
  mx = my = {-1, -1};
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    if (p[i].first > mx.first) {
      mx = p[i];
    } else if (p[i].first == mx.first and p[i].second > mx.second) {
      mx = p[i];
    }
    if (p[i].second > my.second) {
      my = p[i];
    } else if (p[i].second == my.second and p[i].first > my.first) {
      my = p[i];
    }
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int x = p[i].first, y = p[i].second;
    int b = x + y;
    int mxy = b - mx.first;
    int myy = b - my.first;
    if (mxy >= mx.second and myy >= my.second) {
      ans = (ans == -1) ? b : min(ans, b);
    }
  }
  cout << ans << "\n";
  return 0;
}