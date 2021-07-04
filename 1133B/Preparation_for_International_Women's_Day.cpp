#include <iostream>
using namespace std;

int rst[100];

int main () {
    //freopen("in", "r", stdin);
    int n, k;
    scanf("%d %d ", &n, &k);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rst[x % k]++;
    }

    int cnt = rst[0] - rst[0]%2;

    if (k % 2 == 0) {
        cnt += rst[k / 2] - rst[k / 2]%2;
    }

    for (int i = 1; i <= k / 2; i++) {
        if (i == k / 2 && k % 2 == 0)
            break;

        int mini = rst[i];
        if (rst[k - i] < mini)
            mini = rst[k - i];

        cnt += 2 * mini;
    }

    printf ("%d", cnt);
}