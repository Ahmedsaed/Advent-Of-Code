print(sum(len(s[:-1]) - len(eval(s)) for s in open('2015\Day8\input.txt')) + 1)
print(sum(2 + s.count('\\') + s.count('"') for s in open('2015\Day8\input.txt')))

# source: https://www.reddit.com/r/adventofcode/comments/3vw32y/comment/cxrad1k/?utm_source=share&utm_medium=web2x&context=3
