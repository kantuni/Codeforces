""" Created by Henrikh Kantuni and Shahen Kosyan on 3/12/17 """

from itertools import groupby

n = int(input())
seq = list(input())

answer = []
stack = []
depth = -1
for i in range(len(seq)):
    if seq[i] == '[':
        stack.append('[')
        depth += 2
        answer.append(depth)
    else:
        stack.pop()
        answer.append(depth)
        depth -= 2

        if len(stack) == 0:
            answer.append('*')

# break down answer into nested lists using * separator
answer = [list(group) for k, group in groupby(answer, lambda x: x != "*") if k]

max_depth = 0
for i in range(len(answer)):
    if max_depth < max(answer[i]):
        max_depth = max(answer[i])

for i in range(len(answer)):
    answer[i] = [(max_depth + 1 - a) for a in answer[i]]

# flatten
answer = [s for sub in answer for s in sub]

out = ""
stack = []
for i in range(len(answer)):
    line = ""

    if seq[i] == "[" and len(stack) == 0:
        line += " " * ((max_depth - answer[i]) // 2)
        line += "+"
        line += "|" * answer[i]
        line += "+"
        line += " " * ((max_depth - answer[i]) // 2)

        if seq[i + 1] == "]":
            line += " " * ((max_depth - answer[i]) // 2)
            line += "-"
            line += " " * answer[i]
            line += "-"
            line += " " * ((max_depth - answer[i]) // 2)

        stack.append(answer[i])
    elif seq[i] == "[" and len(stack) > 0:
        if seq[i - 1] == "[":
            line += " " * ((max_depth - answer[i] - 2) // 2)
            line += "-"
        else:
            line += " " * ((max_depth - answer[i]) // 2)

        line += "+"
        line += "|" * answer[i]
        line += "+"

        if seq[i - 1] == "[":
            line += "-"
            line += " " * ((max_depth - answer[i] - 2) // 2)
        else:
            line += " " * ((max_depth - answer[i]) // 2)

        if seq[i + 1] == "]":
            line += " " * ((max_depth - answer[i]) // 2)
            line += "-"
            line += " " * answer[i]
            line += "-"
            line += " " * ((max_depth - answer[i]) // 2)

        stack.append(answer[i])
    elif seq[i] == "]":
        if seq[i - 1] == "[":
            line += " " * ((max_depth - answer[i]) // 2)
            line += "-"
            line += " " * answer[i]
            line += "-"
            line += " " * ((max_depth - answer[i]) // 2)

        if i < len(answer) - 1 and seq[i + 1] == "]":
            line += " " * ((max_depth - answer[i] - 2) // 2)
            line += "-"
            line += "+"
            line += "|" * answer[i]
            line += "+"
            line += "-"
            line += " " * ((max_depth - answer[i] - 2) // 2)
        else:
            line += " " * ((max_depth - answer[i]) // 2)
            line += "+"
            line += "|" * answer[i]
            line += "+"
            line += " " * ((max_depth - answer[i]) // 2)

        stack.pop()

    out += line

# divide into chunks of size = max_depth + 2
out = [out[i:i + max_depth + 2] for i in range(0, len(out), max_depth + 2)]

# add a new line between - - and - -
i = 0
while i < len(out):
    if out[i].replace(" ", "") == "--" and out[i + 1].replace(" ", "") == "--":
        out.insert(i + 1, " " * len(out[i]))
    i += 1

vertical = [list(r) for r in out]

# horizontal printing
final = ""
for i in range(len(vertical[0])):
    for j in range(len(vertical)):
        final += vertical[j][i]
    final += "\n"

# remove the trailing space
final = final[:-1]
print(final)
