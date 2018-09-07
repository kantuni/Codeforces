# TLE
if __name__ == "__main__":
    a, b = map(int, input().split())
    c, d = map(int, input().split())

    if (b % 2 == 1 and a % 2 == 0) and (d % 2 == 0 and c % 2 == 0):
        print(-1)
    elif (b % 2 == 0 and a % 2 == 0) and (d % 2 == 1 and c % 2 == 0):
        print(-1)
    else:
        i = 0
        while (b + a * i < d) or (b + a * i - d) % c != 0:
            i += 1

        print(b + a * i)
