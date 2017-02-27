#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

vii merge(vii left, vii right) {
  vii merged;

  int i = 0, j = 0;
  int n = left.size() + right.size();
 
  while (i < left.size() && j < right.size()) {
    if (left[i].first < right[j].first) {
      merged.push_back(left[i]);
      ++i;
    } else {
      merged.push_back(right[j]);
      ++j;
    }
  }

  while (i < left.size()) {
    merged.push_back(left[i]);
    ++i;
  }

  while (j < right.size()) {
    merged.push_back(right[j]);
    ++j;
  }

  return merged;
}

vii merge_sort(vii a) {
  if (a.size() < 2) {
    return a;
  }

  vii left, right;
  
  for (int i = 0; i < a.size() / 2; ++i) {
    left.push_back(a[i]);
  }

  for (int i = a.size() / 2; i < a.size(); ++i) {
    right.push_back(a[i]);
  }

  left = merge_sort(left);
  right = merge_sort(right);
  return merge(left, right);
}

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

  diff = merge_sort(diff);

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