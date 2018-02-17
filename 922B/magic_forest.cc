#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int counter = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < i + j and k < n + 1; k++) {
        int sum = i ^ j ^ k;
        if (sum == 0) counter++;
      }
    }
  }
  cout << counter << "\n";
  return 0;
}
