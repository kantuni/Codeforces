""" Created by Henrikh Kantuni on 3/18/17 """

if __name__ == "__main__":
    n, m = [int(x) for x in input().split()]
    mc = m
    friends = {}

    if m == 0 or m == 1:
        print("YES")
        exit()

    while mc > 0:
        x, y = [int(x) for x in input().split()]

        if x not in friends:
            friends[x] = []
        friends[x].append(y)

        if y not in friends:
            friends[y] = []
        friends[y].append(x)

        mc -= 1

    reasonable = True
    for k in friends.keys():
        for v in friends[k]:
            if len(friends[k]) != len(friends[v]):
                reasonable = False
                break

    if reasonable:
        print("YES")
    else:
        print("NO")
