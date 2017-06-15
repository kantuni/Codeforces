""" Created by Henrikh Kantuni on 2/20/17 """

if __name__ == "__main__":
    n = int(input())
    strengths = [int(s) for s in input().split()]

    maximum = max(strengths)
    minimum = min(strengths)

    count = 0
    for s in strengths:
        if minimum < s < maximum:
            count += 1

    print(count)
