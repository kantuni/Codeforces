""" Created by Henrikh Kantuni on 2/14/17 """

if __name__ == '__main__':
    k, a, b = input().split()
    k, a, b = int(k), int(a), int(b)

    score_a = 0
    if a >= k:
        score_a = int(a / k)

    score_b = 0
    if b >= k:
        score_b = int(b / k)

    if score_a == 0 and score_b == 0:
        print(-1)
    else:
        print(score_a + score_b)
