#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n, m;
  cin >> n >> m;
  vvi finish(n);
  for (int i = 0; i < n; i++) {
    vi row(m);
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
      int min = *min_element(begin(finish[i]), end(finish[i]));
      if (min > 0) {
        for (int j = 0; j < m; j++) {
          finish[i][j] -= min;
        }
        // save steps
        for (int s = 0; s < min; s++) {
          steps += "row " + to_string(i + 1) + "\n";
        }
        count += min;
      }
    }
    // columns
    for (int j = 0; j < m; j++) {
      vi c;
      for (int i = 0; i < n; i++) {
        c.push_back(finish[i][j]);
      }
      int min = *min_element(begin(c), end(c));
      if (min > 0) {
        for (int i = 0; i < n; i++) {
          finish[i][j] -= min;
        }
        // save steps
        for (int s = 0; s < min; s++) {
          steps += "col " + to_string(j + 1) + "\n";
        }
        count += min;
      }
    }
  } else {
    // columns
    for (int j = 0; j < m; j++) {
      vi c;
      for (int i = 0; i < n; i++) {
        c.push_back(finish[i][j]);
      }
      int min = *min_element(begin(c), end(c));
      if (min > 0) {
        for (int i = 0; i < n; i++) {
          finish[i][j] -= min;
        }
        // save steps
        for (int s = 0; s < min; s++) {
          steps += "col " + to_string(j + 1) + "\n";
        }
        count += min;
      }
    }
    // rows
    for (int i = 0; i < n; i++) {
      int min = *min_element(begin(finish[i]), end(finish[i]));
      if (min > 0) {
        for (int j = 0; j < m; j++) {
          finish[i][j] -= min;
        }
        // save steps
        for (int s = 0; s < min; s++) {
          steps += "row " + to_string(i + 1) + "\n";
        }
        count += min;
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
