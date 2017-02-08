""" Created by Henrikh Kantuni on 2/7/17 """

if __name__ == '__main__':
    a = input()
    b = input()

    if len(a) > len(b):
        print(len(a))
    elif len(b) > len(a):
        print(len(b))
    else:
        if a == b:
            print(-1)
        else:
            print(len(a))
