#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<unsigned long long> lengths(n);
  for (int i = 0; i < n; i++) {
    cin >> lengths[i];
  }
  
  sort(lengths.begin(), lengths.end());
  
  bool triangle = false;
  for (int i = 0; i < lengths.size() - 2; i++) {
    if (lengths[i] + lengths[i + 1] > lengths[i + 2]) {
      triangle = true;
      break;
    }
  }

  if (triangle) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
