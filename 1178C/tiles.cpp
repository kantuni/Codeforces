// WA
#include <bits/stdc++.h>
#define M 998244353
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long w, h;
  cin >> w >> h;
  long long ans = (w * h) % M;
  cout << (ans * ans) % M << endl;
  return 0;
}
