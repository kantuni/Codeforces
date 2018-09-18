#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

void print() {
  // TODO:
}

int main() {
  cin >> n;
  a.resize(n);
  int zers = 0, negs = 0;
  int zi = -1, ni = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      zi = (zi == -1) ? i : zi;
      zers++;
    } else if (a[i] < 0) {
      ni = (ni == -1 || a[i] > a[ni]) ? i : ni;
      negs++;
    }
  }
  /*
  if (negs % 2 == 0 and ) {
  if (zers == 1 and negs % 2 == 0) {
    print(n, zi);
  } else if (zers == 0 and negs % 2 == 1) {
    print(n, ni);
  } else {
    print(n);
  }
  */
  print();
  return 0;
}
