import re

lights = set()
lightB = dict()

with open("input.txt") as input: 
    lines = input.readlines()

    for line in lines:
        left, bottom, right, top = re.findall("[0-9]+", line)
        left, bottom, right, top = int(left), int(bottom), int(right), int(top)
        if "turn on" in line:
            for i in range(left, right + 1):
                for j in range(bottom, top + 1):
                    lights.add((i,j))

                    if (i, j) in lightB:
                        lightB[(i, j)] += 1
                    else:
                        lightB[(i, j)] = 1    
        elif "turn off" in line:
            for i in range(left, right + 1):
                for j in range(bottom, top + 1):
                    if (i, j) in lights:
                        lights.remove((i,j))

                    if (i, j) in lightB:
                        if lightB[(i, j)] > 0:
                            lightB[(i, j)] -= 1
                    else:
                        lightB[(i, j)] = 0
        else:
            for i in range(left, right + 1):
                for j in range(bottom, top + 1):
                    if (i, j) in lights:
                        lights.remove((i,j))
                    else:
                        lights.add((i,j))

                    if (i, j) in lightB:
                        lightB[(i, j)] += 2
                    else:
                        lightB[(i, j)] = 2


print("Part 1: " + str(len(lights)))

totalB = lightB.values()
totalB = sum(totalB)

print("Part 2: " + str(totalB))