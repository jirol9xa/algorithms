#include <algorithm>
#include <iostream>
#include <vector>

using Vector = std::vector<long>;

void Qsort(int begin, int end, Vector &vec)
{
    if (end == begin)
        return;

    int left = begin, right = end;
    int pivot = vec[(left + right) / 2];

    while (right >= left) {
        while (vec[left] < pivot)
            ++left;
        while (vec[right] > pivot)
            --right;

        if (left <= right)
            std::swap(vec[left++], vec[right--]);
    }

    if (left < end)
        Qsort(left, end, vec);
    if (right > begin)
        Qsort(begin, right, vec);
}

bool IsVecEq(const Vector &vec1, const Vector &vec2)
{
    for (int i = 0; i < vec1.size(); ++i)
        if (vec1[i] != vec2[i])
            return false;

    return true;
}

void PrintVec(const Vector &vec)
{
    for (auto &&elem : vec)
        std::cout << elem << ' ';
    std::cout << '\n';
}

int main()
{
    Vector vec1(10000);
    Vector vec2(10000);

    do {
        std::cout << "Testing...\n";
        for (int i = 0; i < 10000; ++i)
            vec2[i] = vec1[i] = std::rand();

        Qsort(0, 10000 - 1, vec1);

        std::sort(vec2.begin(), vec2.end());
    } while (IsVecEq(vec1, vec2));

#if 0
    int n;
    std::cin >> n;

    Vector price(n);
    for (int i = 0; i < n; ++i)
        std::cin >> price[i];
    Vector clicks(n);
    for (int i = 0; i < n; ++i)
        std::cin >> clicks[i];

    Qsort(0, n - 1, clicks);
    Qsort(0, n - 1, price);

    long res = 0;
    for (int i = 0; i < n; ++i)
        res += price[i] * clicks[i];

    std::cout << res;
#endif
    return 0;
}
