""" Created by Henrikh Kantuni on 2/24/17 """

if __name__ == "__main__":
    n, m = [int(x) for x in input().split()]
    table = []
    nc = n

    while nc > 0:
        table.append([int(x) for x in input().split()])
        nc -= 1

    k = int(input())
    tasks = []
    kc = k

    while kc > 0:
        l, r = [int(x) for x in input().split()]
        tasks.append((l, r))
        kc -= 1

    for t in tasks:
        l, r = t
        area = table[l - 1:r]

        answer = True
        for j in range(len(area[0])):
            answer = True
            for i in range(1, len(area)):
                if area[i][j] >= area[i - 1][j]:
                    answer = True
                else:
                    answer = False
                    break

            if answer:
                break

        if answer:
            print("Yes")
        else:
            print("No")
