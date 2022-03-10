#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

// data structures
struct Person
{
    string name;
    map<string, int> relations;
};

// function prototypes 
int optimalSeating(Person persons[], int index, string& seat);

int main() {
    ifstream inData;
    Person persons[8];
    string tmp, operation;
    int happines;
    vector<string> names;

    inData.open("input.txt");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++) {
            inData >> persons[i].name >> tmp >> operation >> happines >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp;
            if (operation == "gain")
                persons[i].relations[tmp.substr(0, tmp.length()-2)] = happines;
            else 
                persons[i].relations[tmp.substr(0, tmp.length()-2)] = happines * -1;
        }
        names.push_back(persons[i].name);
    }

    string seat = "";
    cout << "Optimal value: " << optimalSeating(persons, names, seat) << " Seat: " << seat;
}

int optimalSeating(Person persons[], vector<string> names, string& seat) {
        

    return 0;
}