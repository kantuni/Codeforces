#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> lens(n);
  for (int i = 0; i < n; i++) {
    cin >> lens[i];
  }
  sort(lens.begin(), lens.end());
  bool triangle = false;
  for (int i = 0; i < lens.size() - 2; i++) {
    if (lens[i] + lens[i + 1] > lens[i + 2]) {
      triangle = true;
      break;
    }
  }
  if (triangle) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
