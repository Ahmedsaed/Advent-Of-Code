#include <iostream>
#include <fstream>

using namespace std;
bool checkNice(string line);

int main() {
    ifstream cin("input.txt");

    string line;
    int nice_strings = 0;

    while(!cin.eof()) {
        cin >> line;

        if (checkNice(line))
            nice_strings++;
    }

    cout << nice_strings << endl;
}

bool checkNice(string line) {
    if (line.length() <=  3)
        return false;

    bool stop = true;
    for (int i = 1, n = line.length() -1; i < n; i++) {
        if (line[i-1] == line[i+1])
            stop = false;
    }
    if (stop) return false;

    for (int j = 0; j < line.length()-1; j++) {
        string two = string() + line[j] + line[j+1];
        for (int i = j+2; i < line.length() -1; i++) 
            if (two == (string() + line[i] + line[i+1]))
                return true;
    }

    return false;
}