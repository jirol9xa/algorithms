#include <iostream>
#include <list>
#include <utility>

struct Polynom {
    std::list<int> Coefs;
    int            degree;
};

void fillList(Polynom &pol)
{
    auto &[coefs, deg] = pol;
    std::cin >> deg;
    ++deg;

    for (int i = 0; i < deg; ++i) {
        int temp = 0;
        std::cin >> temp;
        coefs.push_back(temp);
    }
}

Polynom add(Polynom &first, Polynom &second)
{
    int min_degree = first.degree, max_degree = second.degree;
    if (min_degree > max_degree)
        std::swap(min_degree, max_degree);

    Polynom res;
    res.degree = max_degree;

    for (int i = 0; i < min_degree; ++i) {
        int result = first.Coefs.back() + second.Coefs.back();

        first.Coefs.pop_back();
        second.Coefs.pop_back();

        res.Coefs.push_front(result);
    }

    auto addRemains = [&res, min_degree, max_degree](Polynom &pol) {
        if (pol.Coefs.empty())
            return;

        for (int i = 0; i < (max_degree - min_degree); ++i) {
            res.Coefs.push_front(pol.Coefs.back());
            pol.Coefs.pop_back();
        }
    };

    addRemains(first);
    addRemains(second);

    return res;
}

int main()
{
    Polynom first;
    fillList(first);
    Polynom second;
    fillList(second);

    Polynom res           = add(first, second);
    auto &[coefs, degree] = res;
    std::cout << degree - 1 << '\n';
    for (auto &elem : coefs) {
        std::cout << elem << ' ';
    }

    return 0;
}
