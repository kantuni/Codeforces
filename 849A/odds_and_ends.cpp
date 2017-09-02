#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> s(n);
  for (int i = 0; i < s.size(); ++i) {
    cin >> s[i];
  }
  
  bool first_is_odd = s[0] % 2 != 0;
  bool last_is_odd = s[s.size() - 1] % 2 != 0;
  bool length_is_odd = s.size() % 2 != 0;
  
  if (first_is_odd && last_is_odd && length_is_odd) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
  
  return 0;
}
