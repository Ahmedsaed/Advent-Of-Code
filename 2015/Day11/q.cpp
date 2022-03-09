#include <iostream>
#include <string>

using namespace std;

bool threeStraightletters(string password);
bool noConfusingCharacters(string password);
bool twoCharPairs(string password);
void incrementPassword(string& password, int last);

int main() {
    // string password = "hxbxwxba";
    string password = "hxbxxyzz";
    
    while (true)
    {
        incrementPassword(password, password.length() - 1);

        // cout << "Checking: " << password << '\n';
        if (noConfusingCharacters(password) && threeStraightletters(password) && twoCharPairs(password)) {
            cout << "Part 2: " << password;
            break;
        }
    }
}

void incrementPassword(string& password, int last) {
    if (password[last] + 1 == 123) {
        password[last] = 'a';
        incrementPassword(password, last - 1);
    }
    else
        password[last]++;
}

bool twoCharPairs(string password) {
    char firstpair = ' ';
    for (int i = 1; i < password.length(); i++) {
        if (firstpair == ' ') {
            if (password[i] == password[i-1])
                firstpair = password[i];
        }
        else {
            if (password[i] == password[i-1] && password[i] != firstpair)
                return true;
        }
    }
    return false;
}

bool noConfusingCharacters(string password) {
    if (password.find('i') < password.length() || password.find('o') < password.length() || password.find('l') < password.length())
        return false;
    return true;
}

bool threeStraightletters(string password) {
    for (int i = 2; i < password.length(); i++)
        if (password[i] == password[i-1] + 1 && password[i-1] == password[i-2] + 1)
            return true;

    return false;
}