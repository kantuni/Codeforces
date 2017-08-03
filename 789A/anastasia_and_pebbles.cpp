#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;
  
  vector<ll> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  
  sort(begin(w), end(w));
  
  ll days = 0;
  for (int i = 0; i < w.size() - 1; i += 2) {
    while (w[i] > 0 || w[i + 1] > 0) {
      w[i] -= min(w[i], k);
      w[i + 1] -= min(w[i + 1], k);
      ++days;
    }
  }
  
  while (w[w.size() - 1] > 0) {
    w[w.size() - 1] -= 2 * min(w[w.size() - 1], k);
    ++days;
  }
  
  cout << days << "\n";
  return 0;
}
