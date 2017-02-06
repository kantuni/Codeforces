#include <iostream>
#include <vector>
using namespace std;

typedef long long big;

int main() {
  int n;
  vector<big> cubes;
  
  // input
  cin >> n;
  for (int i = 0; i < n; ++i) {
    big cube;
    cin >> cube;
    cubes.push_back(cube);
  }

  int i = 0;
  while (i < n / 2) {
    // swap detection
    if (i % 2 == 0) {
      big temp = cubes[i];
      cubes[i] = cubes[cubes.size() - 1 - i];
      cubes[cubes.size() - 1 - i] = temp;
    }
    
    ++i;
  }

  // output
  for (int k = 0; k < cubes.size(); ++k) {
    cout << cubes[k];
    if (k != cubes.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
  
  return 0;
}
