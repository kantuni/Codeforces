""" Created by Henrikh Kantuni on 2/26/17 """

if __name__ == "__main__":
    n = int(input())
    snacks = [int(x) for x in input().split()]

    print(snacks)

    previous_max = max(snacks)
    previous_max_index = snacks.index(previous_max)
