#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream cin("input.txt");

    string line;
    int nice_strings = 0;

    while(!cin.eof()) {
        cin >> line;

        if (line.find("ab") < line.length() || line.find("cd") < line.length() || line.find("pq") < line.length() || line.find("xy") < line.length()) 
            continue;

        bool brk = true;
        for (char& ch : line) {
            string tmp = string() + ch + ch;
            if (line.find(tmp) < line.length()) {
                brk = false;
                break;
            }
        }

        if (brk) continue;

        int n_vowels = 0;

        for (char& ch : line) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                n_vowels++;
        }

        if (!(n_vowels > 2))
            continue;

        nice_strings++;
    }

    cout << nice_strings;
}