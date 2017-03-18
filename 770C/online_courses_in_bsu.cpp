#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
using namespace std;

vector<vector<int>> courses;
unordered_map<int, int> memo;
vector<int> order;
int m;

int c(int cn) {
  if (m > 0) {
    --m;
  } else {
    return -1;
  }
  
  if (courses[cn].size() == 0) {
    memo[cn] = 0;
    order.push_back(cn + 1);
    return 0;
  }
  
  int total = 0;
  for (int i = 0; i < courses[cn].size(); ++i) {
    int key = courses[cn][i] - 1;
    if (memo.find(key) == end(memo)) {
      total += c(courses[cn][i] - 1) + 1;
    } else {
      total += memo[key];
    }
  }
  
  memo[cn] = total;
  order.push_back(cn + 1);
  return total;
}

int main() {
  int n, k;
  cin >> n >> k;
  m = n + 1;
  
  vector<int> primal(k);
  for (int i = 0; i < k; ++i) {
    cin >> primal[i];
  }
  
  for (int i = 0; i < n; ++i) {
    int length;    
    cin >> length;
    
    vector<int> course(length);
    for (int j = 0; j < length; ++j) {
      cin >> course[j];
    }
    
    courses.push_back(course);
  }
  
  for (int i = 0; i < k; ++i) {
    if (memo.find(primal[i] - 1) == end(memo)) {
      c(primal[i] - 1);
    }
  }
  
  if (m > 0) {
    cout << order.size() << "\n";
    for (auto c : order) {
      cout << c << " ";
    }
    cout << "\n";
  } else {
    cout << -1 << "\n";
  }
  
  return 0;
}
