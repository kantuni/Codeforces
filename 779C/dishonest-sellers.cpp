#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int main() {
  int n, k, nc;
  cin >> n >> k;

  vi al;
  nc = n;
  while (nc--) {
    int a;
    cin >> a;
    al.push_back(a);
  }

  vi bl;
  nc = n;
  while (nc--) {
    int b;
    cin >> b;
    bl.push_back(b);
  }

  vii diff;
  for (int i = 0; i < n; ++i) {
    ii d = {al[i] - bl[i], i};
    diff.push_back(d);
  }
  
  sort(begin(diff), end(diff), [](auto &a, auto &b) {
    return a.first < b.first;
  });

  int total = 0;
  int i = 0, min_index;

  while (k--) {
    min_index = diff[i].second;
    total += al[min_index];
    al[min_index] = 0;
    bl[min_index] = 0;
    i++;
  }

  while (i < n and diff[i].first < 0) {
    min_index = diff[i].second;
    total += al[min_index];
    al[min_index] = 0;
    bl[min_index] = 0;
    i++;   
  }

  for (auto value : bl) {
    total += value;
  }

  cout << total << endl;
  return 0;
}
