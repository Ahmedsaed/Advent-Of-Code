from operator import index


def main():
    floor = 0
    with open("2015/Day1/input.txt") as input:
        inData = input.read()

        for index, ch in enumerate(inData):
            if ch == '(':
                floor += 1
            elif ch == ')':
                floor -= 1

            if floor == -1:
                print(index)
        
        print(floor)




main()