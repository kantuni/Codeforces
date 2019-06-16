// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<int>> cnn(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    cnn[a - 1].push_back(b - 1);
    cnn[b - 1].push_back(a - 1);
  }
  long long all = n * (n - 1);
  long long no = cnn[x - 1].size() * cnn[y - 1].size();
  cout << all - no << endl;
  return 0;
}
