#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  if (n == 1 or n == 2) {
    cout << "No" << endl;
  } else {
    vector<int> s1, s2;
    long long sum1 = 0, sum2 = 0;
    for (int i = 1; i < n + 1; i++) {
      if (i % 2) {
        sum1 += i;
        s1.push_back(i);
      } else {
        sum2 += i;
        s2.push_back(i);
      }
    }
    if (gcd(sum1, sum2) > 1) {
      cout << "Yes" << endl;
      cout << s1.size() << " "; 
      for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << " ";
      }
      cout << endl;
      cout << s2.size() << " "; 
      for (int i = 0; i < s2.size(); i++) {
        cout << s2[i] << " ";
      }
      cout << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
