niceStrings = 0

def checkNice(string):
	if(len(string) <= 3):
		return False
	
	for i in range(1,len(string)-1):
		if(string[i-1] == string[i+1]):
			break
	else:
		return False
	
	for j in range(0,len(string)-1):
		two = string[j] + string[j+1]
		for i in range(j+2,len(string)-1):
			if(two == (string[i]+string[i+1])):
				return True

	return False

with open("2015\Day5\input.txt") as input:
    lines = input.readlines()

    for i, line in enumerate(lines):
        if checkNice(line):
            niceStrings += 1

print(niceStrings)


