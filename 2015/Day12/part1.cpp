#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

int getSum (const nlohmann::json& jsonDocument)
{
    auto sum{0};
    for (const auto& [key, value] : jsonDocument.items())
    {
        if(value.is_number())
        {
            sum += value.get<int>();
        }
        else if(value.is_array() || value.is_object())
        {
            sum += getSum (value);
        }
    }
    return sum;
}

int main() {
    std::ifstream file ("input.txt");
    nlohmann::json jsonDocument;
    file >> jsonDocument;

    const auto sum = getSum (jsonDocument);

    cout << "part 1: " << sum;
}
