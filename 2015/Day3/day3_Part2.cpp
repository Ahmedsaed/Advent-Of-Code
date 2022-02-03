#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main()
{
    ifstream inData;
    set<string> positions;
    int  count = 0, xs = 0, ys = 0, xr = 0, yr = 0, i = 0;
    char ch;
    
    string position = "00";
    positions.insert(position);

    inData.open("input.txt");
    while (inData)
    {
        inData >> ch;

        if (i % 2 == 0)
        {
            if (ch == '>')
                xs++;
            else if (ch == '<')
                xs--;
            else if (ch == '^')
                ys++;
            else if (ch == 'v')
                ys--;
            else
                continue;

            position[0] = xs;
            position[1] = ys;
            positions.insert(position);
        }

        if (i % 2 != 0)
        {
            if (ch == '>')
                xr++;
            else if (ch == '<')
                xr--;
            else if (ch == '^')
                yr++;
            else if (ch == 'v')
                yr--;
            else
                continue;

            position[0] = xr;
            position[1] = yr;
            positions.insert(position);
        }

        ch = ' ';
        i++;
    }
    
    inData.close();
    
    cout << positions.size() - 1;
}