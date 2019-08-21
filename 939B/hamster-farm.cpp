#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  int k;
  cin >> n >> k;
  vector<long long> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  long long rem = n;
  long long t = -1;
  for (int i = 0; i < k; i++) {
    if (n / a[i] > 0 and n % a[i] < rem) {
      rem = n % a[i];
      t = i;
    }
  }
  if (t != -1) {
    cout << t + 1 << " ";
    cout << n / a[t] << endl;
  } else {
    cout << "1 0" << endl;
  }
  return 0;
}
