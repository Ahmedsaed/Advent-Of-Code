#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inData;
    char ch;
    int floor = 0, index = 0;

    inData.open("input.txt");

    while (inData)
    {
        inData >> ch;
        if (ch == '(')
            floor++;
        else if (ch == ')')
            floor--;

        ch = ' ';
        
        index++;

        if (floor == -1)
            cout << "Index: " << index << endl;
    }

    cout << floor;
}