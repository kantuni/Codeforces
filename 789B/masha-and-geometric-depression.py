# WA
import math

if __name__ == "__main__":
    b1, q, l, _ = [int(x) for x in input().split()]
    bad = [int(x) for x in input().split()]
    bad = [x for x in bad if x % b1 == 0 and -l <= x <= l]

    if b1 == 0 or q == 0:
        if b1 in bad:
            print(0)
        else:
            print("inf")
        exit()

    if q == 1 or q == -1:
        if b1 in bad:
            print(0)
        else:
            print("inf")
        exit()

    if b1 < 0 and l > 0:
        print("inf")
        exit()

    if b1 > 0 and l > 0 and b1 > l:
        print(0)
        exit()

    n = math.floor(math.log(l / b1, q)) + 1

    count = n
    for i in range(n):
        if b1 * (q ** i) in bad:
            count -= 1

    print(count)
