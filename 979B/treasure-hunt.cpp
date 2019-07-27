// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s0, s1, s2;
  cin >> s0 >> s1 >> s2;
  int m = s0.size();
  if (n < m) {
    unordered_map<char, int> m0, m1, m2;
    for (int i = 0; i < m; i++) {
      m0[s0[i]]++;
      m1[s1[i]]++;
      m2[s2[i]]++;
    }
    int mm0 = 1, mm1 = 1, mm2 = 1;
    for (auto kv: m0) {
      mm0 = max(mm0, kv.second); 
    }
    for (auto kv: m1) {
      mm1 = max(mm1, kv.second);
    }
    for (auto kv: m2) {
      mm2 = max(mm2, kv.second);
    }
    mm0 += n;
    if (mm0 > m) {
      mm0 = (n % 2) ? m - 1 : m;
    }
    mm1 += n;
    if (mm1 > m) {
      mm1 = (n % 2) ? m - 1 : m;
    }
    mm2 += n;
    if (mm2 > m) {
      mm2 = (n % 2) ? m - 1 : m;
    }
    int ans = max({mm0, mm1, mm2});
    if (ans == mm0 and ans != mm1 and ans != mm2) {
      cout << "Kuro" << endl;
    } else if (ans == mm1 and ans != mm0 and ans != mm2) {
      cout << "Shiro" << endl;
    } else if (ans == mm2 and ans != mm0 and ans != mm1) {
      cout << "Katie" << endl;
    } else {
      cout << "Draw" << endl;
    }
  } else {
    cout << "Draw" << endl;
  }
  return 0;
}
