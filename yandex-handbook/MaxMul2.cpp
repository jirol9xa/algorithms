#include <iostream>

int main()
{
    long n = 0;
    std::cin >> n;

    if (((n - 2) * 2 + 1) <= 1.5 * n) {
        std::cout << "No";
        return 0;
    }

    std::cout << "Yes\n" << n;
    for (long i = 1; i < n; i++)
        std::cout << ' ' << i;

    return 0;
}
