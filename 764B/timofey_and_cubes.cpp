#include <iostream>
#include <vector>
using namespace std;

typedef long long big;

int main() {
  int n;
  vector<big> cubes;
  
  cin >> n;
  for (int i = 0; i < n; ++i) {
    big cube;
    cin >> cube;
    cubes.push_back(cube);
  }

  for (int i = 0; i < n / 2; ++i) {
    if (i % 2 == 0) {
      big temp = cubes[i];
      cubes[i] = cubes[cubes.size() - 1 - i];
      cubes[cubes.size() - 1 - i] = temp;
    }
  }

  for (int k = 0; k < cubes.size(); ++k) {
    cout << cubes[k];
    if (k != cubes.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";
  return 0;
}
