#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> cubes(n);
  for (int i = 0; i < n; i++) {
    cin >> cubes[i];
  }
  for (int i = 0; i < n / 2; i++) {
    if (i % 2 == 0) {
      swap(cubes[i], cubes[cubes.size() - 1 - i]);
    }
  }
  for (int k = 0; k < cubes.size(); k++) {
    cout << cubes[k] << " ";
  }
  cout << "\n";
  return 0;
}
