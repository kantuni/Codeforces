""" Created by Henrikh Kantuni on 2/26/17 """

if __name__ == "__main__":
    n, k = [int(x) for x in input().split()]
    al = [int(x) for x in input().split()]
    bl = [int(x) for x in input().split()]

    diff = []
    for i in range(n):
        diff.append((al[i] - bl[i], i))

    diff.sort(key=lambda x: x[0])

    total = 0
    while k > 0:
        min_index = diff[0][1]
        total += al[min_index]
        al[min_index] = 0
        bl[min_index] = 0
        del diff[0]
        k -= 1

    while diff and diff[0][0] < 0:
        min_index = diff[0][1]
        total += al[min_index]
        al[min_index] = 0
        bl[min_index] = 0
        del diff[0]

    for v in bl:
        total += v

    print(total)
