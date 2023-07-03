#include <iostream>
#include <string>

int main()
{
    int size = 0;
    std::cin >> size;

    std::string first, second;
    std::cin >> first >> second;

    for (int i = 0; i < size; ++i) {
        std::cout << first[i] << second[i];
    }

    return 0;
}
