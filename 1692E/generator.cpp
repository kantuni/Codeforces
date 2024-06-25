#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
  return a + rand() % (b - a + 1);
}

int main(int argc, char** argv) {
  int seed = stoi(argv[1]);
  srand(seed);
  cout << 1 << "\n";
  int n = rand(1, 10);
  int s = rand(1, n);
  cout << n << " " << s << "\n"; 
  for (int i = 0; i < n; i++) {
    cout << rand(0, 1) << " ";
  }
  cout << "\n";
  return 0;
}
