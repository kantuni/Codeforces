#include <bits/stdc++.h>
using namespace std;

bool solved(vector<int> color) {
  for (int i = 0; i < 24; i += 4) {
    set<int> s;
    for (int j = 0; j < 4; j++) {
      s.insert(color[i + j]);
    }
    if (s.size() != 1) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> color(24);
  for (int i = 0; i < 24; i++) {
    cin >> color[i];
  }
  vector<int> updated;
  vector<int> from(8), to(8);
  // 1
  from = {1, 3, 5, 7, 9, 11, 22, 20};
  to = {5, 7, 9, 11, 22, 20, 1, 3};
  updated = color;
  for (int i = 0; i < 8; i++) {
    updated[from[i]] = color[to[i]];
  }
  if (solved(updated)) {
    cout << "YES" << endl;
    return 0;
  }
  // 2
  from = {1, 3, 5, 7, 9, 11, 22, 20};
  to = {22, 20, 1, 3, 5, 7, 9, 11};
  updated = color;
  for (int i = 0; i < 8; i++) {
    updated[from[i]] = color[to[i]];
  }
  if (solved(updated)) {
    cout << "YES" << endl;
    return 0;
  }
  // 3
  from = {12, 13, 4, 5, 16, 17, 20, 21};
  to = {4, 5, 16, 17, 20, 21, 12, 13};
  updated = color;
  for (int i = 0; i < 8; i++) {
    updated[from[i]] = color[to[i]];
  }
  if (solved(updated)) {
    cout << "YES" << endl;
    return 0;
  }
  // 4
  from = {12, 13, 4, 5, 16, 17, 20, 21};
  to = {20, 21, 12, 13, 4, 5, 16, 17};
  updated = color;
  for (int i = 0; i < 8; i++) {
    updated[from[i]] = color[to[i]];
  }
  if (solved(updated)) {
    cout << "YES" << endl;
    return 0;
  }
  // 5
  from = {2, 3, 16, 18, 9, 8, 15, 13};
  to = {15, 13, 2, 3, 16, 18, 9, 8};
  updated = color;
  for (int i = 0; i < 8; i++) {
    updated[from[i]] = color[to[i]];
  }
  if (solved(updated)) {
    cout << "YES" << endl;
    return 0;
  }
  // 6
  from = {2, 3, 16, 18, 9, 8, 15, 13};
  to = {16, 18, 9, 8, 15, 13, 2, 3};
  updated = color;
  for (int i = 0; i < 8; i++) {
    updated[from[i]] = color[to[i]];
  }
  if (solved(updated)) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
