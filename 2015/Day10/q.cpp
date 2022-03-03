#include <iostream>
#include <string>

using namespace std;

int main() {
    string data = "1113222113", result = "";
    int counter = 0;
    char last = data[0];

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < data.length(); j++) {
            if (data[j] == last) {
                counter++;
            }
            else {
                result += to_string(counter) + last;
                last = data[j];
                counter = 1;
            }
        }
        result += to_string(counter) + last;

        cout << "Length: " << result.length() << "\n";

        data = result;
        result= "";
        last = data[0];
        counter = 0;
    }
}