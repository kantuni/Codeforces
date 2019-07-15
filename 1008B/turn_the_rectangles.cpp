#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> rects(n);
  for (int i = 0; i < n; i++) {
    cin >> rects[i].first >> rects[i].second;
  }
  if (rects[0].first < rects[0].second) {
    swap(rects[0].first, rects[0].second);
  }
  bool ok = true;
  for (int i = 1; i < n; i++) {
    int h1 = rects[i - 1].first, w1 = rects[i - 1].second;
    int h2 = rects[i].first, w2 = rects[i].second;
    if (h1 >= max(h2, w2)) {
      h2 = max(h2, w2);
      w2 = min(h2, w2);
    } else if (h1 >= min(h2, w2)) {
      h2 = min(h2, w2);
      w2 = max(h2, w2);
    } else {
      ok = false;
    }
    rects[i] = {h2, w2};
  }
  for (int i = 0; i < n - 1; i++) {
    if (rects[i].first < rects[i + 1].first) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
