#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    long n, capacity;
    std::cin >> n >> capacity;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        std::cin >> vec[i];

    std::sort(vec.begin(), vec.end());

    int amnt = 0;
    for (auto &&elem : vec) {
        if (capacity < elem)
            break;

        capacity -= elem;
        ++amnt;
    }

    std::cout << amnt;

    return 0;
}
