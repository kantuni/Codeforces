#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;
  vector<ll> cubes;
  
  // input
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll cube;
    cin >> cube;
    cubes.push_back(cube);
  }

  int i = 0, counter = 1;
  while (i < n / 2) {
    // swap detection
    if (counter % 2 == 1) {
      ll temp = cubes[i];
      cubes[i] = cubes[cubes.size() - 1 - i];
      cubes[cubes.size() - 1 - i] = temp;
    }
    
    ++i;
    ++counter;
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
