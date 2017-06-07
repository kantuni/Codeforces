""" Created by Henrikh Kantuni on 2/14/17 """

if __name__ == "__main__":
    n = int(input())
    home = input()
    
    flights = []
    while n > 0:
        s, t = input().split("->")
        flights.append(s)
        flights.append(t)
        n -= 1

    count = 0
    for flight in flights:
        if flight == home:
            count += 1

    if count % 2 == 0:
        print("home")
    else:
        print("contest")
