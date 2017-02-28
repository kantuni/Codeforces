#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int main() {
  int n, k, nc;
  cin >> n >> k;

  vi al;
  nc = n;
  while (nc > 0) {
    int a;
    cin >> a;
    al.push_back(a);
    --nc;
  }

  vi bl;
  nc = n;
  while (nc > 0) {
    int b;
    cin >> b;
    bl.push_back(b);
    --nc;
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

  while (k > 0) {
    min_index = diff[i].second;
    total += al[min_index];
    al[min_index] = 0;
    bl[min_index] = 0;
    ++i;   
    --k;  
  }

  while (i < n && diff[i].first < 0) {
    min_index = diff[i].second;
    total += al[min_index];
    al[min_index] = 0;
    bl[min_index] = 0;
    ++i;   
  }

  for (auto value : bl) {
    total += value;
  }

  cout << total << endl;

  return 0;
}
