n = int(input())
strengths = [int(s) for s in input().split()]

mx = max(strengths)
mn = min(strengths)

ans = 0
for s in strengths:
    if mn < s < mx:
        ans += 1

print(ans)
