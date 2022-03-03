counter = 0
result = ""

data = "1113222113"

last = data[0]

for i in range(50):
    for char in data:
        if char == last:
            counter += 1
        else:
            result += str(counter) + last
            last = char
            counter = 1
    result += str(counter) + last

    print(f"Iteration {i+1}: " + result + '\n', "Length: " + str(len(result)) + '\n')

    data = result
    result = ""
    last = data[0]
    counter = 0