""" Created by Henrikh Kantuni on 2/7/17 """

a = input()
b = input()
ans = -1 if a == b else max(len(a), len(b))
print(ans)
