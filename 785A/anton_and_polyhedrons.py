n = int(input())

total = 0
faces = {
    "Tetrahedron": 4,
    "Cube": 6,
    "Octahedron": 8,
    "Dodecahedron": 12,
    "Icosahedron": 20,
}

while n > 0:
    total += faces[input()]
    n -= 1

print(total)
