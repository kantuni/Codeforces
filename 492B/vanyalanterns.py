n, l = map(int, input().rstrip().split())
loc = list(map(int, input().rstrip().split()))
loc = sorted(loc)
#print(loc)
#dist = loc[0]
dist = max(loc[0], (l - loc[-1]))
for i in range(n - 1):
    temp = (loc[i + 1] - loc[i]) / 2
    dist = max(dist, temp)
    #print(temp, dist)
print(dist)
    