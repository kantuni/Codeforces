#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> finish(n);
  for (int i = 0; i < n; i++) {
    vector<int> row(m);
    for (int j = 0; j < m; j++) {
      cin >> row[j];
    }
    finish[i] = row;
  }
  int count = 0;
  bool possible = true;
  string steps;
  if (n < m) {
    // rows
    for (int i = 0; i < n; i++) {
      int mn = *min_element(begin(finish[i]), end(finish[i]));
      if (mn > 0) {
        for (int j = 0; j < m; j++) {
          finish[i][j] -= mn;
        }
        // save steps
        for (int s = 0; s < mn; s++) {
          steps += "row " + to_string(i + 1) + "\n";
        }
        count += mn;
      }
    }
    // columns
    for (int j = 0; j < m; j++) {
      vector<int> c;
      for (int i = 0; i < n; i++) {
        c.push_back(finish[i][j]);
      }
      int mn = *min_element(begin(c), end(c));
      if (mn > 0) {
        for (int i = 0; i < n; i++) {
          finish[i][j] -= mn;
        }
        // save steps
        for (int s = 0; s < mn; s++) {
          steps += "col " + to_string(j + 1) + "\n";
        }
        count += mn;
      }
    }
  } else {
    // columns
    for (int j = 0; j < m; j++) {
      vector<int> c;
      for (int i = 0; i < n; i++) {
        c.push_back(finish[i][j]);
      }
      int mn = *min_element(begin(c), end(c));
      if (mn > 0) {
        for (int i = 0; i < n; i++) {
          finish[i][j] -= mn;
        }
        // save steps
        for (int s = 0; s < mn; s++) {
          steps += "col " + to_string(j + 1) + "\n";
        }
        count += mn;
      }
    }
    // rows
    for (int i = 0; i < n; i++) {
      int mn = *min_element(begin(finish[i]), end(finish[i]));
      if (mn > 0) {
        for (int j = 0; j < m; j++) {
          finish[i][j] -= mn;
        }
        // save steps
        for (int s = 0; s < mn; s++) {
          steps += "row " + to_string(i + 1) + "\n";
        }
        count += mn;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (finish[i][j] != 0) {
        possible = false;
        break;
      }
    }
  }
  if (possible) {
    cout << count; << endl;
    cout << steps;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
