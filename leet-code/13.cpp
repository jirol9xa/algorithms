#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

int getNumber(char sym)
{
    switch (sym) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        std::cout << "sym = " << sym << '\n';
        assert(0 && "Invalid case");
    }

    return 0;
}

bool isSecondGreater(char first, char second)
{
    if (first == second)
        return false;

    return getNumber(second) > getNumber(first);
}

int main()
{
    std::string str;
    std::cin >> str;

    std::unordered_map<char, int> sym_map;
    for (auto i = 0; i < str.length() - 1; i++) {
        sym_map[str[i]] += 1 - 2 * isSecondGreater(str[i], str[i + 1]);
    }

    sym_map[str[str.length() - 1]]++;

    size_t res = 0;
    for (auto &elem : sym_map) {
        res += getNumber(elem.first) * elem.second;
    }

    std::cout << res;

    return 0;
}
