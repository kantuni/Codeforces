""" Created by Henrikh Kantuni on 2/20/17 """

if __name__ == "__main__":
    n, l, r = input().split()
    n, l, r = int(n), int(l), int(r)

    li = []
    memo = {}
    m = n

    if n == 0 or n == 1:
        print(n)
        exit()

    if n == 2 or n == 3:
        answer = list(str(n // 2) + str(n % 2) + str(n // 2))
        answer = answer[l - 1:r]
        answer = [a for a in answer if a == '1']

        print(len(answer))
        exit()

    while m // 2 > 1:
        li.append(m // 2)
        m //= 2

    print(li)

    if len(li) == 1:
        memo[li[0]] = str(li[0] // 2) + str(li[0] % 2) + str(li[0] // 2)
    else:
        for i in range(len(li) - 2, -1, -1):
            if li[i - 1] not in memo:
                memo[li[i - 1]] = str(li[i - 1] // 2) + str(li[i - 1] % 2) + str(li[i - 1] // 2)
            previous = memo[li[i - 1]]
            memo[li[i]] = previous + str(li[i] % 2) + previous

    answer = memo[n // 2] + str(n % 2) + memo[n // 2]
    answer = list(answer)
    print(answer)
    answer = answer[l - 1:r]
    answer = [a for a in answer if a == '1']

    print(len(answer))
