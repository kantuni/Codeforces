#include <iostream>
using namespace std;

int main () {
    //freopen("in", "r", stdin);
    int h1, m1;
    scanf("%d:%d", &h1, &m1);
    int h2, m2;
    scanf("%d:%d", &h2, &m2);

    int hs = h2 - h1;
    int ms = 60 * hs + m2 - m1;

    ms /= 2;
    //printf ("%d\n", ms);
    while (m1 + ms >= 60) {
        h1++;
        ms -= 60;
    }

    if (h1 < 10)
        printf ("0%d:", h1);
    else
        printf ("%d:", h1);

    if (m1 + ms < 10)
        printf ("0%d", m1 + ms);
    else
        printf ("%d", m1 + ms);
}