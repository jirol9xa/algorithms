#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using Vector = std::vector<int64_t>;

int64_t findMaxMul(const Vector &vec)
{
    int size = vec.size();

    long max1 = vec[0], max2 = vec[1];
    if (max2 > max1)
        std::swap(max2, max1);

    long old_max1 = 0;

    for (int i = 2; i < size; ++i) {
        auto elem = vec[i];

        if (elem > max1) {
            old_max1 = max1;
            max1     = elem;
            continue;
        }
        if (elem > max2)
            max2 = elem;
    }

    max2 = std::max(max2, old_max1);

    return max1 * max2;
}

int64_t findMaxMulNaive(Vector vec)
{
    int     size = vec.size();
    int64_t res  = 0;

    std::sort(vec.begin(), vec.end());

    return vec[size - 1] * vec[size - 2];
}

Vector generate(int upper_bound, int size)
{
    Vector vec(size);

    for (int i = 0; i < size; ++i)
        vec[i] = std::rand() % upper_bound;

    return vec;
}

void dumpVec(const Vector &vec)
{
    std::cout << "Vector: ";
    for (auto &elem : vec)
        std::cout << elem << ' ';

    std::cout << '\n';
}

int main()
{
#if 1
    int size = 0;
    std::cin >> size;

    Vector vec(size);
    for (int i = 0; i < size; ++i)
        std::cin >> vec[i];

    std::cout << findMaxMul(vec);
#endif

#if 0
    for(;;) {
        std::vector<int> vec = generate(10000, 10000);
        if (auto res1 = findMaxMul(vec), res2 = findMaxMulNaive(vec); res1 != res2) {
            std::cout << "Wrong answer!\n";
            dumpVec(vec);
            std::cout << "res = " << res1 << ", res naive = " << res2 << '\n';
            
            return 0;
        }

        std::cout << "OK\n";
    }
#endif
    return 0;
}
