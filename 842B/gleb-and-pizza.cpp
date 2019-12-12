#include <bits/stdc++.h>
using namespace std;

struct Sausage {
  int x, y, r;
};

int main() {
  int r, d;
  cin >> r >> d;
  int n;
  cin >> n;
  vector<Sausage> sausages;
  for (int i = 0; i < n; i++) {
    int xi, yi, ri;
    cin >> xi >> yi >> ri;
    Sausage s;
    s.x = xi;
    s.y = yi;
    s.r = ri;
    sausages.push_back(s);
  }
  int ans = 0;
  for (int i = 0; i < sausages.size(); i++) {
    Sausage s = sausages[i];
    double R = hypot(s.x, s.y);
    bool outside = true;
    if (R <= r - s.r) {
      outside = false;
    }
    bool main = false;
    if (R < r - d + s.r) {
      main = true;
    }
    if (!outside and !main) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
