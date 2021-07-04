#include <iostream>
#include <algorithm>
using namespace std;

int v[200000];

int main () {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &v[i]);
    }

    int maxi = 0;
    int len = 0;
    int st = 0;

    sort (v, v + n);
    for (int i = 0; i < n; i++) {
        len++;
        while (v[i] > v[st] + 5) {
            st++;
            len--;
        }
        if (len > maxi)
            maxi = len;
    }

    printf ("%d", maxi);
}