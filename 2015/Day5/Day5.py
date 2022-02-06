niceStrings = 0

with open("2015\Day5\input.txt") as input:
    lines = input.readlines()

    for i, line in enumerate(lines):
        if "ab" in line or "cd" in line or "pq" in line or "xy" in line:
            continue
        
        for ch in line:
            if ch + ch in line:
                break
        else:
            continue

        nVowels = 0

        for ch in line:
            if ch is 'a' or ch is 'e' or ch is 'i' or ch is 'o' or ch is 'u':
                nVowels += 1
        
        if not(nVowels > 2):
            continue

        print(line)
        niceStrings += 1

print(niceStrings)