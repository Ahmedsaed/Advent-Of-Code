inputFile = open("input.txt", 'r')
x, y = 0, 0
positions = {(0, 0)}

for ch in inputFile.read():
    if ch == '>':
        x += 1
    elif ch == '<':
        x -= 1
    elif ch == '^':
        y += 1
    elif ch == 'v':
        y -= 1

    positions.add((x,y))

print(len(positions))

