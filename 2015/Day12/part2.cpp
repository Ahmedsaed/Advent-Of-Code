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
        else if(value.is_string() && jsonDocument.is_object())
        {
            if(value.get<std::string>() == "red")
            {
                sum = 0;
                break;
            }
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
