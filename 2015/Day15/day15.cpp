#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const n_ingredient = 4;
int const total_spoons = 100;

struct Ingredient {
    string name;
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;
    int n_spoons = 0;
} ingredients[n_ingredient];


void bestIng(int lastIng, int& maxScore) {
    if (lastIng > 3) {
        int total_spoons = 0;

        for (int i = 0; i < n_ingredient; i++)
        {
            total_spoons += ingredients[i].n_spoons;
        }

        if (total_spoons != 100) return;

        long long int score = 0;
        int capacity = 0;
        int durability = 0;
        int flavor = 0;
        int texture = 0;
        int calories = 0;

        for (int i = 0; i < n_ingredient; i++)
        {
            capacity += ingredients[i].capacity * ingredients[i].n_spoons;
            durability += ingredients[i].durability * ingredients[i].n_spoons;
            flavor += ingredients[i].flavor * ingredients[i].n_spoons;
            texture += ingredients[i].texture * ingredients[i].n_spoons;
            calories += ingredients[i].calories * ingredients[i].n_spoons;
        }

        capacity = max(capacity, 0);
        durability = max(durability, 0);
        flavor = max(flavor, 0);
        texture = max(texture, 0);
        
        if (calories != 500) return; // comment this line for part 1

        score = capacity * durability * flavor * texture;
        
        if (score > maxScore)
            maxScore = score;
        
        return;
    }
        
    lastIng++;
    int remaningSpoons = 100;

    for (int i = 0; i < n_ingredient; i++)
    {
        remaningSpoons -= ingredients[i].n_spoons;
    }
    
    for (int i = 1; i <= remaningSpoons; i++)
    {
        ingredients[lastIng - 1].n_spoons = i;
        bestIng(lastIng, maxScore);
        ingredients[lastIng - 1].n_spoons = 0;
    }
}


int main() {
    ifstream cin("input.txt");

    string tmp;
    int Ntmp;

    for (int i = 0; i < n_ingredient; i++)
    {
        cin >> tmp;
        ingredients[i].name = tmp.substr(0, tmp.length() - 1);
        cin >> tmp >> Ntmp;
        ingredients[i].capacity = Ntmp;
        cin >> tmp >> tmp >> Ntmp;
        ingredients[i].durability = Ntmp;
        cin >> tmp >> tmp >> Ntmp;
        ingredients[i].flavor = Ntmp;
        cin >> tmp >> tmp >> Ntmp;
        ingredients[i].texture = Ntmp;
        cin >> tmp >> tmp >> Ntmp;
        ingredients[i].calories = Ntmp;
    }
    
    int maxScore = -1;

    bestIng(0, maxScore);

    cout << "MaxScore: " << maxScore << endl;

    return 0;
}

