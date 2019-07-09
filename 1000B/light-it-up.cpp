// WA
#include <bits/stdc++.h>
using namespace std;

long long power(vector<int> a) {
  long long sum = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    if (i % 2 == 0) {
      sum += a[i + 1] - a[i];
    }
  }
  return sum;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 2, 0);
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  a[n + 1] = m;
  int diff = 0, index = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i + 1] - a[i] > diff) {
      diff = a[i + 1] - a[i];
      index = i;
    }
  }
  long long ans = power(a);
  if (index % 2 == 1) {
    a.insert(a.begin() + index + 1, a[index] + 1);
  } else if (index == 0) {
    a.insert(a.begin() + 1, a[1] - 1);
  }
  bool good = true;
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i + 1] <= a[i]) {
      good = false;
      break;
    }
  }
  if (good) {
    ans = max(ans, power(a));
  }
  cout << ans << endl;
  return 0;
}
