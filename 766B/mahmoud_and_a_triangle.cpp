#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

typedef unsigned long long huge;

vector<huge> counting_sort(vector<huge> A, int base, int digit) {
  vector<list<huge>> buckets(base);

  for (auto item: A) {
    int index = (item / (int) pow(base, digit)) % base;
    buckets[index].push_back(item);
  }

  vector<huge> B;
  for (auto bucket: buckets) {
    if (!bucket.empty()) {
      for (auto item: bucket) {
        B.push_back(item);
      }
    }
  }

  return B;
}

vector<huge> radix_sort(vector<huge> A) {
  int base = A.size();
  huge max = *max_element(begin(A), end(A));

  int digits = 0;
  while (max / base > 0) {
    max = max / base;
    ++digits;
  }

  vector<huge> B(A);
  for (int i = 0; i <= digits; ++i) {
    B = counting_sort(B, base, i);
  }

  return B;
}

int main() {
  int n;
  cin >> n;

  vector<huge> lengths;
  for (int i = 0; i < n; ++i) {
    huge length;
    cin >> length;
    lengths.push_back(length);
  }
  
  lengths = radix_sort(lengths);

  int i = 0;
  bool triangle = false;
  while (i < lengths.size() - 2) {
    if (lengths[i] + lengths[i + 1] > lengths[i + 2]) {
      triangle = true;
      break;
    }

    ++i;
  }

  if (triangle) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
