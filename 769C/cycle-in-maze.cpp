#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

const char dl[] = {'D', 'L', 'R', 'U'};
const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};

int n, m, k;
vector<vector<char>> g;
vector<vector<int>> dist, color;

void bfs(int sr, int sc) {
  queue<tuple<int, int, int>> q;
  q.push({sr, sc, 0});
  while (!q.empty()) {
    auto [r, c, d] = q.front(); q.pop();
    bool roob = r < 0 or r >= n;
    bool coob = c < 0 or c >= m;
    if (roob or coob or g[r][c] == '*' or color[r][c] == 1) {
      continue;
    }
    q.push({r + 1, c, d + 1});
    q.push({r - 1, c, d + 1});
    q.push({r, c + 1, d + 1});
    q.push({r, c - 1, d + 1});
    dist[r][c] = d;
    color[r][c] = 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  g.assign(n, vector<char>(m));
  dist.assign(n, vector<int>(m, INF));
  color.assign(n, vector<int>(m, 0));
  int sr, sc;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> g[r][c];
      if (g[r][c] == 'X') {
        sr = r, sc = c;
        g[r][c] = '.';
      }
    }
  }
  bfs(sr, sc);
  string ans;
  int r = sr, c = sc;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 4; j++) {
      int nr = r + dr[j], nc = c + dc[j];
      bool roob = nr < 0 or nr >= n;
      bool coob = nc < 0 or nc >= m;
      if (roob or coob or g[nr][nc] == '*') {
        continue;
      }
      if (dist[nr][nc] < k - i) {
        r = nr, c = nc;
        ans += dl[j];
        break;
      }
    }
  }
  if (k % 2 == 1 or ans.size() != k) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
