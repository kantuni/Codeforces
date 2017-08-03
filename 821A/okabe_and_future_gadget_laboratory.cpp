#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> lab(n);
  for (int i = 0; i < n; ++i) {
    vector<int> row(n);
    for (int j = 0; j < n; ++j) {
      cin >> row[j];
    }
    lab[i] = row;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (lab[i][j] != 1) {
        bool good = false;
        for (int k = 0; k < n; ++k) {
          for (int l = 0; l < n; ++l) {
            if (k != j && l != i && lab[i][k] + lab[l][j] == lab[i][j]) {
              good = true;
              break;
            }
          }
        }
        
        if (!good) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  
  cout << "Yes\n";
  return 0;
}
