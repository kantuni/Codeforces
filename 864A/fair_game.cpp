#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> count(101, 0);
  set<int> s;
  
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    s.insert(a);
    count[a] += 1;
  }
  
  // set -> vector
  vector<int> sv(s.begin(), s.end());
  
  if (sv.size() == 2 && count[sv[0]] == count[sv[1]]) {
    cout << "YES" << "\n";
    cout << sv[0] << " " << sv[1] << "\n";
  } else {
    cout << "NO" << "\n";
  }
  
  return 0;
}
