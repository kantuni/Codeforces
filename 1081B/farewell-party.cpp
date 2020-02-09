// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> memo;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]]++;
    sum += a[i];
  }
  vector<int> b(n);
  bool possible = false;
  if (sum == 0) {
    possible = true;
    fill(b.begin(), b.end(), 1);
  } else if (memo.size() == 1) {
    auto it = memo.begin();
    if (it->first == n - 1) {
      possible = true;
      for (int i = 0; i < n; i++) {
        b[i] = i + 1;
      }
    } else if (n % 2 == 0 and it->first == n / 2 and it->second == n) {
      possible = true;
      for (int i = 0; i < n / 2; i++) {
        b[i] = 1;
      }
      for (int i = n / 2; i < n; i++) {
        b[i] = 2;
      }
    }
  } else if (memo.size() == 2) {
    auto it1 = memo.begin();
    auto it2 = next(it1);
    possible = it1->first == it2->second and it1->second == it2->first;
    b = a;
  }
  if (possible) {
    cout << "Possible" << endl;
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
