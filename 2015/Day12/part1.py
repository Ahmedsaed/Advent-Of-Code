import re

def main():
    numbers = []
    input = open('input.txt', 'r')

    for line in input.readlines():
        numbers.extend(map(int, re.findall('-?\d+\.?\d*', line)))

    print(sum(numbers))

main()