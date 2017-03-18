""" Created by Henrikh Kantuni on 3/15/17 """

from decimal import *

if __name__ == "__main__":
    n, m = [int(x) for x in input().split()]

    if m >= n:
        print(n)
    else:
        days = Decimal((-1 + Decimal(1 + 8 * (n - m)) ** Decimal(0.5)) / 2)
        answer = days.to_integral_exact(rounding=ROUND_CEILING) + m
        print(answer)
