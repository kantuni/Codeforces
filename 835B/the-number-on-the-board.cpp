#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vull;
typedef vector<vull> vvull;

int main() {
  ull k;
  string n;
  cin >> k >> n;
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  vvull digits(10);
  ull sum = 0;
  for (ull i = 0; i < n.size(); i++) {
    int digit = n[i] - '0';
    sum += digit;
    digits[digit].push_back(i);
  }
  ull col = 0, row = 0;
  ull mnd = 0;
  while (sum < k) {
    if (row >= digits[col].size()) {
      col++;
      row = 0;
    }
    if (digits[col].size() == 0) {
      col++;
      continue;
    }
    int index = digits[col][row];
    sum -= n[index] - '0';
    n[index] = '9';
    sum += 9;
    row++;
    mnd++;
  }
  cout << mnd << endl;
  return 0;
}
