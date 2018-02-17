#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
  ull n; int k;
  cin >> n >> k;
  
  vector<ull> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  
  ull left = n, type;
  for (int i = 0; i < k; i++) {
    if (n / a[i] > 0 and n % a[i] < left) {
      left = n % a[i];
      type = i;
    }
  }
  
  if (left != n) {
    cout << type + 1 << " " << n / a[type] << "\n";
  } else {
    cout << "1 0\n";
  }
  return 0;
}
