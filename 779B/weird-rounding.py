""" Created by Henrikh Kantuni on 2/26/17 """

n, k = [int(x) for x in input().split()]
digits = list(str(n))

zero_count = digits.count('0')
if zero_count < k:
    print(len(str(n)) - 1)
    exit()

count = 0
i = len(digits) - 1

while int(''.join(digits)) % 10 ** k > 0:
    if digits[i] != '0':
        del digits[i]
        count += 1
    i -= 1

print(count)
