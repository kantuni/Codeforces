initial = input().split()
n = int(input())

victims = []
m = n
while m > 0:
    s, t = input().split()
    victims.append([s, t])
    m -= 1

answer = initial[0] + " " + initial[1]

for i in range(len(victims)):
    if initial[0] == victims[i][0]:
        initial[0] = victims[i][1]
        answer += "\n" + initial[0] + " " + initial[1]
    elif initial[1] == victims[i][0]:
        initial[1] = victims[i][1]
        answer += "\n" + initial[0] + " " + initial[1]

print(answer)
