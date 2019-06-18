k, a, b = [int(x) for x in input().split()]

score_a = 0
if a >= k:
    score_a = a // k

score_b = 0
if b >= k:
    score_b = b // k

if score_a == 0 and score_b == 0:
    print(-1)
elif score_a == 0:
    if b % k == 0:
        print(score_b)
    else:
        print(-1)
elif score_b == 0:
    if a % k == 0:
        print(score_a)
    else:
        print(-1)
else:
    print(score_a + score_b)
