#include <bits/stdc++.h>
#define FLAG 1000000001
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), zers, negs;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      zers.push_back(i);
    } else if (a[i] < 0) {
      negs.push_back(i); 
    }
  }
  int left = n;
  if (negs.size() % 2 == 0 and zers.size() > 0) {
    // multiply all zeroes 
    for (int i = 0; i < zers.size() - 1; i++) {
      cout << "1 " << zers[i] + 1 << " ";
      cout << zers[i + 1] + 1 << endl;
      a[zers[i]] = FLAG;
      left--;
    }
    // remove the last zero
    if (left > 1) {
      cout << "2 " << zers[zers.size() - 1] + 1 << endl;
      a[zers[zers.size() - 1]] = FLAG;
      left--;
    }
  } else if (negs.size() % 2 == 1 and zers.size() == 0) {
    // find the largest negative
    int mn = a[negs[0]], mni = negs[0];
    for (int i = 1; i < negs.size(); i++) {
      if (a[negs[i]] > mn) {
        mn = a[negs[i]];
        mni = negs[i];
      }
    }
    // remove the largest negative
    if (left > 1) {
      cout << "2 " << mni + 1 << endl;
      a[mni] = FLAG;
      left--;
    }
  } else if (negs.size() % 2 == 1 and zers.size() > 0) {
    // multiply all zeroes
    for (int i = 0; i < zers.size() - 1; i++) {
      cout << "1 " << zers[i] + 1 << " ";
      cout << zers[i + 1] + 1 << endl;
      a[zers[i]] = FLAG;
      left--;
    }
    // find the largest negative
    int mn = a[negs[0]], mni = negs[0];
    for (int i = 1; i < negs.size(); i++) {
      if (a[negs[i]] > mn) {
        mn = a[negs[i]];
        mni = negs[i];
      }
    }
    // multiply it by the last zero
    cout << "1 " << mni + 1 << " ";
    cout << zers[zers.size() - 1] + 1 << endl;
    a[mni] = FLAG;
    left--;
    // remove the last zero
    if (left > 1) {
      cout << "2 " << zers[zers.size() - 1] + 1 << endl;
      a[zers[zers.size() - 1]] = FLAG;
      left--;
    }
  }
  // multiply the rest
  vector<int> rest;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != FLAG) {
      rest.push_back(i + 1);
    }
  }
  for (int i = 0; i < rest.size() - 1; i++) {
    cout << "1 " << rest[i] << " ";
    cout << rest[i + 1] << endl;
  }
  return 0;
}
