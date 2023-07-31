#include <iostream>

int getPeriodLen(int m) {
    int cur = 1;
    int prev = 0;

    for (int period = 0; ; ++period) {
        int tmp = cur;
        cur = (cur + prev) % m;
        prev = tmp;

        if (cur == 1 && prev == 0)
            return period + 1;
    }
}

int calcLastNum(int n, int m) {
    int cur = 1;
    int prev = 0;

    for (int i = 1; i < n; ++i) {
        int tmp = cur;
        cur = (cur + prev) % m;
        prev = tmp;
    }

    return cur;
}

int calcLastNumLL(long long n, int m) {
    int cur = 1;
    int prev = 0;

    for (int i = 1; i < n; ++i) {
        int tmp = cur;
        cur = (cur + prev) % m;
        prev = tmp;
    }

    return cur;
}

int main() {
    long long n = 0;
    int m = 0;
    //std::cin >> n >> m;

    //std::cout << calcLastNum(n % getPeriodLen(m), m); 

    std::cout << "Testing started\n";

    for (;;) {
        int n = std::rand() % INT32_MAX;
        int m = std::rand() % INT32_MAX;
        if (calcLastNum(n % getPeriodLen(m), m) != calcLastNumLL(n, m)) {
            std::cout << "n = " << n << ", m = " << m << '\n';
            return EXIT_FAILURE;
        }
    }

    return 0;
}
