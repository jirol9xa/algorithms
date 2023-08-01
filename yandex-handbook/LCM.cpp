#include <cstdint>
#include <iostream>

uint64_t GCD(uint64_t a, uint64_t b)
{
    if (a == 0 || b == 0)
        return std::max(a, b);
    else
        return GCD(b, a % b);
}

int main()
{
    uint64_t a, b;
    std::cin >> a >> b;

    std::cout << a * b / GCD(a, b);
}
