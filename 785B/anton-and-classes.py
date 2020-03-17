""" Created by Henrikh Kantuni on 3/15/17 """

if __name__ == "__main__":
    n = int(input())
    min_r1 = 2 * 10 ** 9
    max_l1 = 0

    while n > 0:
        l1, r1 = [int(x) for x in input().split()]
        if r1 < min_r1:
            min_r1 = r1
        if l1 > max_l1:
            max_l1 = l1
        n -= 1

    m = int(input())
    min_r2 = 2 * 10 ** 9
    max_l2 = 0

    while m > 0:
        l2, r2 = [int(x) for x in input().split()]
        if r2 < min_r2:
            min_r2 = r2
        if l2 > max_l2:
            max_l2 = l2
        m -= 1

    if max_l2 - min_r1 >= 0 and max_l1 - min_r2 >= 0:
        print(max(max_l2 - min_r1, max_l1 - min_r2))
    elif max_l2 - min_r1 >= 0:
        print(max_l2 - min_r1)
    elif max_l1 - min_r2 >= 0:
        print(max_l1 - min_r2)
    else:
        print(0)
