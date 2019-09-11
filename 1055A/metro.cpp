#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
vector<vector<int>> color;
bool found;
int n, s;

void dfs(int i, int dir) {
  color[i][dir] = 1;
  if (i == s - 1) {
    found = true;
    return;
  }
  if (dir == 0) {
    for (int j = i; j < n; j++) {
      if (a[j] == 1 and color[j][dir] == 0) {
        dfs(j, dir);
      }
      if (a[j] * b[j] == 1 and color[j][!dir] == 0) {
        dfs(j, !dir);
      }
    }
  } else if (dir == 1) {
    for (int j = i; j > -1; j--) {
      if (b[j] == 1 and color[j][dir] == 0) {
        dfs(j, dir);
      }
      if (a[j] * b[j] == 1 and color[j][!dir] == 0) {
        dfs(j, !dir);
      }
    }
  }
}

int main() {
  cin >> n >> s;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  color.assign(n, vector<int>(2));
  found = false;
  if (a[0] == 1) {
    dfs(0, 0);
  }
  if (found) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
