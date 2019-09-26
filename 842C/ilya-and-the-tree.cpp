// WA
#include <bits/stdc++.h>
using namespace std;

struct Node {
  bool root = false;
  int parent;
  int weight;
};

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int best_gcd(vector<int> numbers) {
  int best = numbers[numbers.size() - 1];
  int min = best;
  int min_index = numbers.size() - 1;
  for (int i = numbers.size() - 1; i > -1; i--) {
    if (gcd(best, numbers[i]) < min) {
      min = gcd(best, numbers[i]);
      min_index = i;
    }
  }
  if (min_index != numbers.size() - 1) {
    numbers[min_index] = 0;
  }
  for (int i = 0; i < numbers.size(); i++) {
    best = gcd(best, numbers[i]);
  }
  return best;
}

int main() {
  int n;
  cin >> n;
  vector<Node> nodes(n);
  nodes[0].root = true;
  for (int i = 0; i < n; i++) {
    cin >> nodes[i].weight;
  }
  for (int i = 0; i < n - 1; i++) {
    int s, t;
    cin >> s >> t;
    nodes[t - 1].parent = s - 1;
  }
  for (int i = 0; i < nodes.size(); i++) {
    vector<int> path;
    int current = i;
    while (nodes[current].root != true) {
      path.push_back(nodes[current].weight);
      current = nodes[current].parent;
    }
    path.push_back(nodes[current].weight);
    cout << best_gcd(path) << " ";
  }
  cout << endl;
  return 0;
}
