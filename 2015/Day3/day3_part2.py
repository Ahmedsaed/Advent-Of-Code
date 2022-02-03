inputFile = open("input.txt", 'r')
x, y = 0, 0
positions = {(0, 0)}

inData = inputFile.read()

for i, ch in enumerate(inData):
    if i % 2 == 0:
        if ch == '>':
            x += 1
        elif ch == '<':
            x -= 1
        elif ch == '^':
            y += 1
        elif ch == 'v':
            y -= 1

    positions.add((x,y))

x, y = 0, 0

for i, ch in enumerate(inData):
    if i % 2 != 0:
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

