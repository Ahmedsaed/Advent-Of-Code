from re import L


def main():
    with open("/home/ahmed/Documents/Advent-Of-Code/2015/Day2/input.txt") as input:
        lines = input.readlines()

        t_area, t_ribbon = 0, 0
        for line in lines:
            l, w, h = map(int, line[:-1].split("x"))

            t_area += 2 * l * w + 2 * w * h + 2 * l * h
            
            sides = [l, w ,h]
            sides.sort()

            t_area += sides[0] * sides[1]

            t_ribbon += 2 * (sides[0] + sides[1]) + (sides[0] * sides[1] * sides[2])

    print(t_area, "  ", t_ribbon)


main()