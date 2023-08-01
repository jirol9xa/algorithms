#include <cstdint>
#include <iostream>

uint64_t getPeriodLen(uint64_t m)
{
    uint64_t next = 1;
    uint64_t curr = 0;

    uint64_t period = 0;
    for (;;) {
        auto tmp = next;
        next     = (next + curr) % m;
        curr     = tmp;

        period++;
        if (curr == 0 && next == 1)
            return period;
    }
}

uint64_t calcLastNum(long long int n, long long int m)
{
    if (n == 0)
        return 0;

    uint64_t next = 1;
    uint64_t curr = 0;

    for (uint64_t i = 1; i < n; ++i) {
        auto tmp = next;
        next     = (next + curr) % m;
        curr     = tmp;
    }

    return next;
}

int main()
{
    uint64_t n = 0;
    std::cin >> n;

    auto mod = calcLastNum((n + 2) % getPeriodLen(10), 10);

    std::cout << mod - 1 + 10 * (mod == 0);

    return 0;
}
