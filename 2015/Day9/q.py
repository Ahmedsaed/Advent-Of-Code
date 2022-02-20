from copy import deepcopy

def main():
    with open("2015\Day9\input.txt") as input:
        lines = input.readlines()

        cities = []
        for line in lines:
            for word in line[:-1].split():
                if not word.isdecimal() and word not in cities and word not in ['to', '=']:
                    cities.append(word)
        
        routes = []
        routes.append(list(route(city, lines, cities) for city in cities))

        print("Part 1: ", min(flatten(routes)))
        print("Part 2: ", max(flatten(routes)))

def route(city, lines, cities, visitedCities = [], distance = 0, currentRoute = ""):
    visitedCities = deepcopy(visitedCities)
    visitedCities.append(city)
    currentRoute += city + " -> "
    distances = []

    for i, ct in enumerate(cities):
        if ct not in visitedCities:
            currentDistance = int(list(str(line).split()[-1] for line in lines if city in line and ct in line)[0])
            distance += currentDistance
            distances.append(route(ct, lines, cities, visitedCities, distance, currentRoute))
            distance -= currentDistance

    if len(distances) == 0:
        # if distance < 100:
        print(currentRoute + str(distance))
        return distance

    return flatten(distances)

def flatten(x):
    result = []
    for el in x:
        if hasattr(el, "__iter__") and not isinstance(el, str):
            result.extend(flatten(el))
        else:
            result.append(el)
    return result
            
main()