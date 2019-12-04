#include <bits/stdc++.h>
using namespace std;

int mpow(int x, int y) {
  int ans = 1;
  while (y > 0) {
    if (y % 2 == 0) {
      ans = (ans * ans) % 2;
      y /= 2;
    } else {
      ans = (ans * x) % 2;
      y--; 
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int b, k;
  cin >> b >> k;
  vector<int > a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = k - 1; i > -1; i--) {
    ans += a[i] * mpow(b, k - 1 - i) % 2;
  }
  if (ans % 2 == 0) {
    cout << "even" << endl;
  } else {
    cout << "odd" << endl;
  }
  return 0;
}
