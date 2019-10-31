#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[200000];
bool Passed[200000];

int main () {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d %d ", &n, &m);

    int nod = 0;
    int maxi = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);

        if (v[a].size() > maxi) {
            maxi = v[a].size();
            nod = a;
        }

        if (v[b].size() > maxi) {
            maxi = v[b].size();
            nod = b;
        }
    }

    queue<int> q;

    q.push(nod);
    Passed[nod] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < v[node].size(); i++) {
            int vec = v[node][i];

            if (!Passed[vec]) {
                q.push(vec);
                Passed[vec] = true;
                printf ("%d %d\n", node, vec);
            }
        }
    }
}