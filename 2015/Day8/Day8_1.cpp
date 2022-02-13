/*
    code by adham asm
*/

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
    outData.open("outfile.txt");

    int orgcalc=0, rescalc=0;
    for (int i = 0; i < 300; i++)
    {
        getline(input, list[i]);
    }

    for (int i = 0 ; i < 300 ; i++)
    {
        for (int j = 0 ; j < list[i].length() ; j++)
        {
            orgcalc++;
        }
    }

    for (int i = 0 ; i < 300 ; i++)
    {
        for (int j = 0 ; j < list[i].length() ;)
        {
            if (list[i][j] == '\"') { j++; }
            else if (list[i][j] == '\\')
            {
                if (list[i][j+1] == '\\')
                {
                    outData << '\\';
                    rescalc++;
                    j += 2;
                }
                else if (list[i][j+1] == '\"')
                {
                    outData << '\"';
                    rescalc++;
                    j += 2;
                }
                else if (list[i][j+1] == 'x')
                {
                    outData << 'k';
                    rescalc++;
                    j += 4;
                }
            }
            else
            {
                outData << list[i][j];
                rescalc++;
                j++;
            }
        }

        outData << endl;
    }

    input.close();
    outData.close();
    cout << orgcalc - rescalc;
}