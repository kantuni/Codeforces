#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, nc;
  vector<int> snacks;

  cin >> n;
  nc = n;
  while (nc > 0) {
    int snack;
    cin >> snack;
    snacks.push_back(snack);
    --nc;
  }
  
  vector<int> indexes(n + 1);
  indexes[0] = -1;
  
  for (int i = 1; i < snacks.size(); ++i) {
    indexes[snacks[i]] = i;
  }
  
  for (int i = 0; i < indexes[n]; ++i) {
    cout << "\n";
  }
  cout << snacks[indexes[n]];
  
  int previous = indexes[n];
  for (int i = n - 1; i > 0; --i) {
    if (indexes[i] < previous) {
      cout << " " << snacks[indexes[i]];
    } else {
      int before = indexes[i] - previous;
      while (before > 0) {
        cout << endl;
        --before;
      }
      cout << snacks[indexes[i]];
      previous = indexes[i];
    }
  }
  cout << "\n";
  
  return 0;
}
