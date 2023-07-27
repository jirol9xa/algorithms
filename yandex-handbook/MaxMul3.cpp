#include <algorithm>
#include <iostream>
#include <vector>

struct SmallDuo {
    long min1 = 0;
    long min2 = 0;

    SmallDuo(const std::vector<long> &vec) : min1(vec.at(0)), min2(vec.at(1))
    {
        if (min1 > min2)
            std::swap(min1, min2);

        auto min3 = vec.at(2);

        if (min1 > min3) {
            min2 = min1;
            min1 = min3;

            return;
        }

        if (min2 > min3)
            min2 = min3;
    }

    void compare(long num)
    {
        if (min2 < num)
            return;

        if (min1 > num) {
            min2 = min1;
            min1 = num;

            return;
        }

        min2 = num;
    }
};

struct BigTrio {
    long max1 = 0;
    long max2 = 0;
    long max3 = 0;

    BigTrio(const std::vector<long> &vec)
        : max1(vec.at(0)), max2(vec.at(1)), max3(vec.at(2))
    {
        if (max1 < max2)
            std::swap(max1, max2);

        if (max1 < max3) {
            std::swap(max1, max3);
            std::swap(max3, max2);
        }
        else if (max2 < max3)
            std::swap(max2, max3);
    }

    void compare(long num)
    {
        if (num < max3)
            return;

        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;

            return;
        }

        if (num > max2) {
            max3 = max2;
            max2 = num;

            return;
        }

        max3 = num;
    }
};

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<long> vec(n);
    for (int i = 0; i < n; ++i)
        std::cin >> vec[i];

    BigTrio  maxes(vec);
    SmallDuo mins(vec);
    auto     begin_iter = vec.begin();
    std::advance(begin_iter, 3);

    std::for_each(begin_iter, vec.end(), [&](long num) {
        maxes.compare(num);
        mins.compare(num);
    });

    long max_mul1 = maxes.max1 * maxes.max2 * maxes.max3;
    long max_mul2 = maxes.max1 * mins.min1 * mins.min2;

    std::cout << std::max(max_mul1, max_mul2);

    return 0;
}
