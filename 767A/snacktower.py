if __name__ == "__main__":
    n = int(input())
    snacks = [int(s) for s in input().split()]

    output = ''
    old_max = max(snacks)
    old_index = snacks.index(old_max)

    new_max = old_max
    new_index = old_index

    while snacks:
        output += '\n' * new_index
        output += str(new_max) + ' '
        snacks = snacks[new_index + 1:]

        if snacks:
            old_max = new_max
            new_max = max(snacks)
            old_index = new_index
            new_index = snacks.index(new_max)
            i = old_max - 1

            while i != new_max:
                output += str(i) + ' '
                i -= 1

            output = output[:-1]
            output += '\n' * (new_index - old_index)
        else:
            j = new_max - 1
            while j != 0:
                output += str(j) + ' '
                j -= 1
            output = output[:-1]

    print(output)
