#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ifstream inData;
    set<tuple<int, int>> position;
    int  count = 0, x = 0, y = 0;
    char ch;

    inData.open("input.txt");

    tuple <int, int, int> position;
    position = make_tuple(0, 0, 0);

    position.insert(position);
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

        position.insert(make_tuple(x , y));
    }
    
    cout << position.size();
}