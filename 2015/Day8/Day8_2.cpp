#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream input;
    ofstream outData;
    string list[300];

    input.open("input.txt");
    outData.open("outfile_2.txt");

    int before = 0, after = 0;

    for (int i = 0; i < 300; i++)
    {
        getline(input, list[i]);
    }

    for (int i = 0 ; i < 300 ; i++)
    {
        for (int j = 0 ; j < list[i].length() ; j++)
        {
            before++;
        }
    }
    
    for (int i = 0 ; i < 300 ; i++)
    {
        after += 2;
        outData << "\"";
        for (int j = 0; j < list[i].length();)
        {
            if (list[i][j] == '\"') 
            {
                outData << "\\\"";
                j++;
                after += 2;
            }
            else if (list[i][j] == '\\')
            {
                outData << "\\\\";
                j++;
                after += 2;
            }
            else
            {
                outData << list[i][j];
                after++;
                j++;
            }
        }
        outData << "\"";
        outData << endl;
    }
    
    input.close();
    cout << after - before;
}