#include <iostream>
#include <fstream>
#include <string>

#define n_reindeers 9
#define length 2503

using namespace std;

struct Reindeer {
    string name;
    int speed;
    int moveDuration;
    int restDuration;
    int totalDistance = 0;
    int score = 0;
    int restLast = length;
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

    int race_length = length;
    while (race_length > 0)
    {
        race_length--;

        for (int i = 0; i < n_reindeers; i++)
        {
            if (reindeers[i].restLast > race_length) {
                reindeers[i].totalDistance += reindeers[i].speed;
                // reindeers[i].score += reindeers [i].speed;\
                if (reindeers[i].totalDistance % (reindeers[i].speed * reindeers[i].moveDuration) == 0)
                    reindeers[i].restLast = race_length - reindeers[i].restDuration;
            }
        }

        int MaxDistance = 0;
        for (int i = 0; i < n_reindeers; i++)
            if (reindeers[i].totalDistance > MaxDistance)
                MaxDistance = reindeers[i].totalDistance;

        for (int i = 0; i < n_reindeers; i++) 
            if (reindeers[i].totalDistance == MaxDistance)
                reindeers[i].score++;
    }
    
    string winnerName;
    int winnerTT = 0;
    for (int i = 0; i < n_reindeers; i++) {
        cout << reindeers[i].name << " Completed: " << reindeers[i].score << endl;
        if (reindeers[i].score > winnerTT) {
            winnerTT = reindeers[i].score;
            winnerName = reindeers[i].name;
        }
    }
    cout << "The winner is " << winnerName << ". Completed: " << winnerTT;

}