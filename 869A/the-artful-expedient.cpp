#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;
  
  set<ull> s;
  
  vector<ull> x;
  for (int i = 0; i < n; i++) {
    ull xi;
    cin >> xi;
    x.push_back(xi);
    s.insert(xi);
  }
  
  vector<ull> y;
  for (int i = 0; i < n; i++) {
    ull yi;
    cin >> yi;
    y.push_back(yi);
    s.insert(yi);
  }
  
  ull counter = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ull xxy = x[i] ^ y[j];
      if (s.count(xxy) > 0) {
        counter++;
      }
    }
  }
  
  if (counter % 2 == 0) {
    cout << "Karen" << "\n";
  } else {
    cout << "Koyomi" << "\n";
  }
  
  return 0;
}
