#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inData;
    char ch;
    int l = 0, w = 0, h = 0;
    long tarea = 0, tribbon = 0;

    inData.open("input.txt");

    while (inData)
    {
        inData >> l;
        inData >> ch;
        inData >> w;
        inData >> ch;
        inData >> h;

        tarea += 2 * l * w + 2 * w * h + 2 * l * h;

        int sides[] = {l , w, h};
        sort(sides, sides + 3);

        tarea += sides[0] * sides[1];

        l = 0;
        w = 0;
        h = 0;

        tribbon += 2 * (sides[0] + sides[1]) + (sides[0] * sides[1] * sides[2]);
    }

    cout << tarea << " " << tribbon;
}