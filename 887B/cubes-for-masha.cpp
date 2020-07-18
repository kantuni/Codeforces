#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v1, v2, v3;
  vector<int> visited(1000, 0);
  for (int i = 0; i < 6; i++) {
    int tmp;
    cin >> tmp;
    v1.push_back(tmp);
    visited[tmp] = 1;
  }
  if (n > 1) {
    for (int i = 0; i < 6; i++) {
      int tmp;
      cin >> tmp;
      v2.push_back(tmp);
      visited[tmp] = 1;
    }
  }
  if (n > 2) { 
    for (int i = 0; i < 6; i++) {
      int tmp;
      cin >> tmp;
      v3.push_back(tmp);
      visited[tmp] = 1;
    }
  }
  // 1-2
  for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v2.size(); j++) {
      string index = to_string(v1[i]) + to_string(v2[j]);
      sort(index.begin(), index.end());
      do {
        visited[stoi(index)] = 1;
      } while (next_permutation(index.begin(), index.end()));
    }
  }
  // 1-3
  for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v3.size(); j++) {
      string index = to_string(v1[i]) + to_string(v3[j]);
      sort(index.begin(), index.end());
      do {
        visited[stoi(index)] = 1;
      } while (next_permutation(index.begin(), index.end()));
    }
  }
  // 2-3
  for (int i = 0; i < v2.size(); i++) {
    for (int j = 0; j < v3.size(); j++) {
      string index = to_string(v2[i]) + to_string(v3[j]);
      sort(index.begin(), index.end());
      do {
        visited[stoi(index)] = 1;
      } while (next_permutation(index.begin(), index.end()));
    }
  }
  // 1-2-3
  for (int i = 0; i < v1.size(); i++) {
    for (int j = 0; j < v2.size(); j++) {
      for (int k = 0; k < v3.size(); k++) {
        string index = to_string(v1[i]) + to_string(v2[j]) + to_string(v3[k]);
        sort(index.begin(), index.end());
        do {
          visited[stoi(index)] = 1;
        } while (next_permutation(index.begin(), index.end()));
      }
    }
  }
  for (int i = 1; i < 1000; i++) {
    if (visited[i] == 0) {
      cout << i - 1 << endl;
      break;
    }
  }
  return 0;
}
