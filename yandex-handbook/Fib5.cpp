#include <cstdint>
#include <iostream>

int calcLastNum(int n)
{
    if (n <= 1)
        return n;

    int next = 1;
    int curr = 1;

    for (int i = 2; i < n; ++i) {
        int tmp = next;
        next    = (next + curr) % 10;
        curr    = tmp;
    }

    return next;
}

int main()
{
    uint_fast64_t n, m;
    std::cin >> m >> n;

    // Pisano period for 10 is 60
    auto last_n = calcLastNum((n + 2) % 60);
    last_n += 10 * (last_n == 0) - 1;

    auto last_m = calcLastNum((m + 1) % 60);
    last_m += 10 * (last_m == 0) - 1;

    auto res = last_n - last_m;
    std::cout << res + 10 * (res < 0);

    return 0;
}
