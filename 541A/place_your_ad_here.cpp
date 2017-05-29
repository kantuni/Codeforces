#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main() {
  int n, m;
  int nc, mc;
  cin >> n >> m;
  
  vii commercials;
  nc = n;
  while (nc > 0) {
    int l, r;
    cin >> l >> r;
    ii range = {l, r};
    commercials.push_back(range);
    --nc;
  }
  
  viii channels;
  mc = m;
  while (mc > 0) {
    int a, b, c;
    cin >> a >> b >> c;
    iii range = {a, b, c};
    channels.push_back(range);
    --mc;
  }
  return 0;
}
