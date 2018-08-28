n, m = map(int, input().split())
a = 1
for i in range(n - 1):
  a *= 10
  a += 1
b = 10 ** n - a
print(a)
print(b)
