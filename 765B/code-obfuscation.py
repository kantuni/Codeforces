obfuscation = list(input())
letters = list("abcdefghijklmnopqrstuvwxyz")

if len(obfuscation) == 1:
    if obfuscation[0] == 'a':
        print("YES")
    else:
        print("NO")
else:
    while len(obfuscation) > 0:
        if obfuscation[0] == letters[0]:
            while letters[0] in obfuscation:
                obfuscation.remove(letters[0])
            letters.remove(letters[0])
        else:
            print("NO")
            exit()

    print("YES")
