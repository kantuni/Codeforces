#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  string answer = "";
  for (int i = 0; i < n; ++i) {
    answer += 'a';
  }
  
  for (int i = 2; i < n; i += 4) {
    answer[i] = 'b';
    if (i + 1 < n) {
      answer[i + 1] = 'b';
    }
  }
  
  cout << answer << "\n";
  return 0; 
}
