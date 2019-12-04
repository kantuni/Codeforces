import math

n = int(input())
answer = ""
if n < 3:
    print(1)
else:
    print(2)

m = n + 2
numbers = [True] * m
numbers[0] = False
numbers[1] = False

for i in range(2, int(math.sqrt(m)) + 1):
    j = 0
    while i ** 2 + j * i < m:
        numbers[i ** 2 + j * i] = False
        j += 1

for i in range(2, m):
    if numbers[i]:
        answer += "1 "
    else:
        answer += "2 "

answer = answer[:-1]
print(answer)
