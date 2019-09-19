// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<int> cx, cy, s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool ok = i - 1 >= 0 and j - 1 >= 0 and i + 1 < n and j + 1 < m;
      bool horizontal = ok and g[i - 1][j] == '*' and g[i + 1][j] == '*';
      bool vertical = ok and g[i][j - 1] == '*' and g[i][j + 1] == '*';
      bool star = g[i][j] == '*' and horizontal and vertical;
      if (star) {
        cx.push_back(i);
        cy.push_back(j);
        s.push_back(1);
      }
    }
  }
  for (int i = 0; i < cx.size(); i++) {
    for (int len = 1; len < min(n, m); len++) {
      bool ok = cx[i] - len >= 0 and cy[i] - len >= 0 and cx[i] + len < n and cy[i] + len < m;
      bool horizontal = ok and g[cx[i] - len][cy[i]] != '.' and g[cx[i] + len][cy[i]] != '.';
      bool vertical = ok and g[cx[i]][cy[i] - len] != '.' and g[cx[i]][cy[i] + len] != '.';
      bool star = g[cx[i]][cy[i]] != '.' and horizontal and vertical;
      if (star) {
        s[i] = len;
        g[cx[i] - len][cy[i]] = '#';
        g[cx[i] + len][cy[i]] = '#';
        g[cx[i]][cy[i]] = '#';
        g[cx[i]][cy[i] - len] = '#';
        g[cx[i]][cy[i] + len] = '#';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '*') {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << cx.size() << endl;
  for (int i = 0; i < cx.size(); i++) {
    cout << cx[i] + 1 << " " << cy[i] + 1 << " " << s[i] << endl;
  }
  return 0;
}
