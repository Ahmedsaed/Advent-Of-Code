#include <iostream>
#include <string>
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"

using namespace std;

int main() {
    Poco::MD5Engine md5;
    string hash = "iwrupvqb", result = "";
    int hashnum = 0;

    while (true)
    {
        md5.update(hash + to_string(hashnum));
        result = Poco::DigestEngine::digestToHex(md5.digest());
        
        if ("000000" == result.substr(0, 6)) {
            cout << hashnum << endl;
            break;
        }
        else {
            hashnum++;
            // if (hashnum % 10000 == 0)
            //     cout << hashnum << endl;
        }
    }
}