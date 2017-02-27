""" Created by Henrikh Kantuni on 2/14/17 """

if __name__ == "__main__":
    n = int(input())
    home = input()
    flights = []
    while n > 0:
        _from, _to = input().split("->")
        flights.append(_from)
        flights.append(_to)
        n -= 1

    count = 0
    for f in flights:
        if f == home:
            count += 1

    if count % 2 == 0:
        print("home")
    else:
        print("contest")
