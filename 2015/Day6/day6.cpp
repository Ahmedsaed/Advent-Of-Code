#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

int main()
{
    ifstream inData;

    inData.open("input.txt");

    string command, tmp;
    char comma;
    int left, bottom, right, top;

    int* lights = new int[1000000];
    
    lights[0] = 1;

    while (inData)
    {
        inData >> command;
        if (command == "turn")
        {
            inData >> command >> left >> comma >> bottom >> tmp >> right >> top;
            if (command == "on")
            {

            }
            else
            {

            }
        }
        else
        {
            inData >> left >> comma >> bottom >> tmp >> right >> top;

        }
    }
    cout << lights[0];
}