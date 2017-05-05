#include <iostream>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  
  char l[n][m];
  int ri, rj;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char symbol;
      cin >> symbol;
      if (symbol == 'X') {
        ri = i;
        rj = j;
        l[i][j] = '.';
      } else {
        l[i][j] = symbol;
      }
    }
  }
  
  if (k % 2 != 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  
  int steps = 0;
  string answer = "";
  
  while (steps < k / 2) {
    if (ri < n && l[ri + 1][rj] == '.') {
      // down
      answer += "D";
      ++ri;
    } else if (rj > 0 && l[ri][rj - 1] == '.') {
      // left
      answer += "L";
      --rj;
    } else if (rj < m && l[ri][rj + 1] == '.') {
      // right
      answer += "R";
      ++rj;
    } else if (ri > 0 && l[ri - 1][rj] == '.') {
      // up
      answer += "U";
      --ri;
    } else {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    
    ++steps;
  }
  
  for (int i = answer.length() - 1; i >= 0; --i) {
    switch (answer[i]) {
      case 'U': {
        answer += "D";
        break;
      }
      case 'R': {
        answer += "L";
        break;
      }
      case 'D': {
        answer += "U";
        break;
      }
      case 'L': {
        answer += "R";
        break;
      }
    }
  }
  
  cout << answer << endl;
  return 0;
}
