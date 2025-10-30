#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <utility>

class HashMap {
public:
    HashMap() {
        values = std::vector<std::list<Var>>(10);
    }

    void add(std::string key, int value) {
        int hash = hashGen(key);

        values[hash].push_back({key, value});
    }

    int getValue(std::string key) {
        int hash = hashGen(key);

        for(Var vars : values[hash]) {
            if (vars.key == key)
                return vars.value;
        }

        return -1;
    }

private:
    struct Var{
        std::string key;
        int value;
    };

    std::vector<std::list<Var>> values;

    std::string toLowercase(std::string value)
    {
        std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c){ return std::tolower(c); });
        return value;
    }

    int hashGen(std::string value) {
        value = toLowercase(value);
        int total = 0;
        for(char c : value) {
            total += static_cast<int>(c) - 97;
        }
        if (total > 99)
            return static_cast<int>(total / 100);
        return static_cast<int>(total / 10);
    }
};

int main() {
    HashMap hashMap;
    hashMap.add("Hissamu", 101);

    std::cout << hashMap.getValue("Hissamu") << "\n";

    return 0;
}


