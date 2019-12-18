#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int n, A, B, C, T;
  cin >> n >> A >> B >> C >> T;
  vector<int> t(n);
  int mnt = INF;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    mnt = min(mnt, t[i]);
  }
  if (mnt > T) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> c(n, A);
  int ans1 = n * A;
  int ans2 = 0;
  for (int i = 0; i < n; i++) {
    int k = T - t[i];
    ans2 += A - k * B;
    ans2 += C * k;
  }
  cout << max(ans1, ans2) << endl;
  return 0;
}
