#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> snacks(n);
  for (int i = 0; i < n; i++) {
    cin >> snacks[i];
  }
  vector<int> id(n + 1);
  for (int i = 1; i < n; i++) {
    id[snacks[i]] = i;
  }
  for (int i = 0; i < id[n]; i++) {
    cout << endl;
  }
  cout << snacks[id[n]];
  int previous = id[n];
  for (int i = n - 1; i > 0; i--) {
    if (id[i] < previous) {
      cout << " " << snacks[id[i]];
    } else {
      int before = id[i] - previous;
      while (before--) {
        cout << endl;
      }
      cout << snacks[id[i]];
      previous = id[i];
    }
  }
  cout << endl;
  return 0;
}
