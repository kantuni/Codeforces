// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  vector<double> slopes;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double slope = 1.0 * (y[j] - y[i]) / (j - i);
      slopes.push_back(slope);
    }
  }
  sort(slopes.begin(), slopes.end());
  int index = 0;
  int counter = 1;
  int max = 1;
  for (int i = 1; i < slopes.size(); i++) {
    if (slopes[i] == slopes[i - 1]) {
      counter++;
    } else {
      counter = 1;
    }
    if (counter > max) {
      max = counter;
      index = i;
    }
  }
  double common = slopes[index];
  vector<bool> points(n, false);
  vector<double> b;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double slope = 1.0 * (y[j] - y[i]) / (j - i);
      if (slope == common) {
        points[i] = true;
        points[j] = true;
        double bi = y[i] - slope * (i + 1);
        double bj = y[j] - slope * (j + 1);
        b.push_back(bi);
        b.push_back(bj);
      }
    }
  }
  // remove duplicates
  set<double> s(b.begin(), b.end());
  b.assign(s.begin(), s.end());
  int miss = 1;
  bool all_used = true;
  for (int i = 0; i < n; i++) {
    if (points[i] == false) {
      if (miss == 0) {
        all_used = false;
        break;
      } else {
        miss--;
      }
    }
  }
  if (all_used and b.size() == 2) {
    cout << "Yes" << endl;
  } else if (all_used and miss == 0 and b.size() == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
