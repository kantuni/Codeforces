""" Created by Henrikh Kantuni on 3/23/17 """

n, m = map(int, input().split())
destroy = False

while m > 0:
    group = [int(g) for g in input().split()][1:]

    if len(group) == 1:
        destroy = True
        break

    group = [abs(g) for g in list(set(group))]
    old_size = len(group)
    group = list(set(group))

    if len(group) == old_size:
        destroy = True
        break

    m -= 1

if destroy:
    print("YES")
else:
    print("NO")
