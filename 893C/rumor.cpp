#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

priority_queue<ii> pq;
vvii cnn;
vi taken;

void process(int u) {
  taken[u] = 1;
  for (int j = 0; j < cnn[u].size(); j++) {
    ii v = cnn[u][j];
    if (!taken[v.first]) {
      pq.push(ii(-v.second, -v.first));
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  
  cnn.resize(n + 1);
  taken.assign(n + 1, 0);
  
  for (int i = 1; i <= n; i++) {
    ll c;
    cin >> c;
    cnn[0].push_back(ii(i, c));
    cnn[i].push_back(ii(0, c));
  }
  
  while (m--) {
    int s, t;
    cin >> s >> t;
    cnn[s].push_back(ii(t, 0));
    cnn[t].push_back(ii(s, 0));
  }
  
  process(0);
  ll mst = 0;
  while (!pq.empty()) {
    ii front = pq.top();
    pq.pop();
    ll u = -front.second;
    ll w = -front.first;
    if (!taken[u]) {
      mst += w;
      process(u);
    }
  }
  
  cout << mst << endl;
  return 0;
}
