#include <iostream>
#include <fstream>
#include <string>

#define n_reindeers 9
#define race_length 2503

using namespace std;

struct Reindeer {
    string name;
    int speed;
    int moveDuration;
    int restDuration;
    int totalDistance = 0;
    bool isResting = false;
};

int main() {
    ifstream inData;

    inData.open("input.txt");

    Reindeer reindeers[n_reindeers];
    int i = 0;
    string tmp;

    while (!inData.eof())
    {
        inData >> reindeers[i].name >> tmp >> tmp >> reindeers[i].speed >> tmp >> tmp >> reindeers[i].moveDuration
               >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> reindeers[i].restDuration >> tmp;
        i++;
    }

    for (int i = 0; i < n_reindeers; i++)
    {
        int racer_length = race_length;
        while (racer_length > 0)
        {
            racer_length--;
            reindeers[i].totalDistance += reindeers[i].speed;
            if (reindeers[i].totalDistance % (reindeers[i].speed * reindeers[i].moveDuration) == 0)
                racer_length -= reindeers[i].restDuration;
        }
    }
    
    string winnerName;
    int winnerTT = 0;
    for (int i = 0; i < n_reindeers; i++) {
        cout << reindeers[i].name << " Completed: " << reindeers[i].totalDistance << endl;
        if (reindeers[i].totalDistance > winnerTT) {
            winnerTT = reindeers[i].totalDistance;
            winnerName = reindeers[i].name;
        }
    }
    cout << "The winner is " << winnerName << ". Completed: " << winnerTT;

}