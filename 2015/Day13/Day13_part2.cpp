#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

// definations
#define n_persons 9

// data structures
struct Person
{
    string name;
    map<string, int> relations;
};

// function prototypes 
int optimalSeating(Person persons[], vector<string> names, int& result, int index);
int totalHappiness(Person persons[], vector<string> names);

int main() {
    ifstream inData;
    Person persons[n_persons];
    string tmp, operation;
    int happines;
    vector<string> names;

    inData.open("input.txt");

    for (int i = 0; i < n_persons - 1; i++)
    {
        for (int j = 0; j < n_persons - 2; j++) {
            inData >> persons[i].name >> tmp >> operation >> happines >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp;
            if (operation == "gain")
                persons[i].relations[tmp.substr(0, tmp.length()-1)] = happines;
            else 
                persons[i].relations[tmp.substr(0, tmp.length()-1)] = happines * -1;
        }
        persons[i].relations["me"] = 0;
        persons[n_persons-1].name = "me";
        persons[n_persons-1].relations[persons[i].name] = 0;
    }

    int result = 0;
    optimalSeating(persons, names, result, 0);
    cout << "Optimal value: " << result;
}

int optimalSeating(Person persons[], vector<string> names, int& result, int index) {
    int tmp = 0;
    // seat += " " + persons[index].name;
    names.push_back(persons[index].name);

    if (names.size() == n_persons) {
        // cout << totalHappiness(persons, names) << endl;
        return totalHappiness(persons, names);
    }

    for (int i = 0; i < n_persons; i++) {
        if (!count(names.begin(), names.end(), persons[i].name)) {
            tmp = optimalSeating(persons, names, result, i);
            if(result < tmp)
                result = tmp;
        }
    }

    return result;
}

int totalHappiness(Person persons[], vector<string> names) {
    int result = 0;
    for (int i = 0; i < n_persons; i++) {
        for (int j = 0; j < n_persons; j++) {
            if (persons[j].name == names[i]) {
                result += persons[j].relations[names[(i+1) % n_persons]];
                result += persons[j].relations[names[(n_persons+i-1) % n_persons]];
            }
        }
    }
    return result;
}