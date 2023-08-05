#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using Spice = std::pair<double, long>;

double calcValue(long capacity, std::vector<Spice> &spices)
{
    if (capacity == 0 || spices.empty())
        return 0;

    double value = 0;
    for (auto &&[cost, weight] : spices) {
        long res_weight = std::min(capacity, weight);

        value += cost * res_weight;

        capacity -= res_weight;
        if (capacity == 0)
            break;
    }

    return value;
}

int main()
{
    long amnt = 0, capacity = 0;
    std::cin >> amnt >> capacity;
    if (capacity == 0) {
        std::cout << "0.000";
        return 0;
    }

    std::vector<Spice> vec(amnt);
    for (int i = 0; i < amnt; ++i) {
        long cost, weight;
        std::cin >> cost >> weight;
        if (weight != 0)
            vec[i] = {cost / double(weight), weight};
    }

    std::sort(vec.begin(), vec.end(),
              [](Spice elem1, Spice elem2) { return elem1.first > elem2.first; });

    std::cout << std::fixed << std::setprecision(3) << calcValue(capacity, vec);

    return 0;
}
