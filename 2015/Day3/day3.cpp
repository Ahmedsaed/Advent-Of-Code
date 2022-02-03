#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main()
{
    ifstream inData;
    set<string> positions;
    int  count = 0, x = 0, y = 0;
    char ch;
    string position = "00";

    inData.open("input.txt");

    positions.insert(position);

    while (inData)
    {
        inData >> ch;
        if (ch == '>')
            x++;
        else if (ch == '<')
            x--;
        else if (ch == '^')
            y++;
        else if (ch == 'v')
            y--;

        position[0] = x;
        position[1] = y;

        positions.insert(position);
    }
    
    cout << positions.size();
}