/*
Check the python answer in day3.py
*/

#include <iostream>
#include <fstream>
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
    positions.insert(position);

    inData.open("input.txt");
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