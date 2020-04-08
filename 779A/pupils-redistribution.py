""" Created by Henrikh Kantuni on 2/26/17 """

n = int(input())
al = [int(x) for x in input().split()]
bl = [int(x) for x in input().split()]
a = {
    1: al.count(1),
    2: al.count(2),
    3: al.count(3),
    4: al.count(4),
    5: al.count(5),
}
b = {
    1: bl.count(1),
    2: bl.count(2),
    3: bl.count(3),
    4: bl.count(4),
    5: bl.count(5),
}

possible = True
for key in a.keys():
    if (a[key] + b[key]) % 2 != 0:
        possible = False
        break

if possible:
    swaps = 0
    for key in a.keys():
        if a[key] > b[key]:
            swaps += (a[key] - b[key]) // 2
    print(swaps)
else:
    print(-1)
