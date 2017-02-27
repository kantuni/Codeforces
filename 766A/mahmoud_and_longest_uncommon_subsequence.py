""" Created by Henrikh Kantuni on 2/7/17 """

if __name__ == "__main__":
    a = input()
    b = input()

    if a == b:
        print(-1)
    else:
        print(max(len(a), len(b)))
