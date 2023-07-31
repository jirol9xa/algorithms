#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0;
        return 0;
    }

    int prev = 0;
    int cur  = 1;
    for (int i = 1; i < n; ++i) {
        int tmp = cur;
        cur     = (cur + prev) % 10;
        prev    = tmp;
    }

    std::cout << cur;

    return 0;
}
