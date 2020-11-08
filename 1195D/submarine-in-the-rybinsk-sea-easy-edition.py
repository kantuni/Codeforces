# TLE
def f(l, r):
    ls = str(l)
    rs = str(r)
    fs = ""
    for i in range(len(ls)):
        fs += ls[i]
        fs += rs[i]
    return int(fs) % M


M = 998244353
n = int(input())
a = [int(x) for x in input().split()]

ans = 0
for i in range(n):
    for j in range(n):
        ans += f(a[i], a[j])
        ans %= M

print(ans)
