#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;

  vector<ull> lengths(n);
  for (int i = 0; i < n; ++i) {
    cin >> lengths[i];
  }
  
  sort(begin(lengths), end(lengths));

  bool triangle = false;
  for (int i = 0; i < lengths.size() - 2; ++i) {
    if (lengths[i] + lengths[i + 1] > lengths[i + 2]) {
      triangle = true;
      break;
    }
  }

  if (triangle) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
