n, l, r = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

before = True
for i in range(0, l - 1):
    if a[i] != b[i]:
        before = False
        break

after = True
for i in range(r, len(a)):
    if a[i] != b[i]:
        after = False
        break

if before and after:
    print("TRUTH")
else:
    print("LIE")
