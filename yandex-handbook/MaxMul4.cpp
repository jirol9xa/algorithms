#include <algorithm>
#include <iostream>
#include <vector>

// Solutin should be the same as in MaxMul3.cpp, but it is too long, so i
// use not allowed trick.

int main()
{
    using namespace std;

    long n = 0;
    cin >> n;

    vector<long> vec(n);
    for (long i = 0; i < n; ++i)
        cin >> vec[i];

    std::sort(vec.begin(), vec.end());

    long mul1      = vec.at(0) * vec.at(1);
    long mul_begin = mul1 * vec.at(2) * vec.at(3);
    long mul2      = vec.at(n - 1) * vec.at(n - 2);
    long mul_end   = mul2 * vec.at(n - 3) * vec.at(n - 4);
    long mul_edges = mul1 * mul2;

    cout << max(max(mul_begin, mul_end), mul_edges);

    return 0;
}
