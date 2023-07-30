#include <cassert>
#include <iostream>
#include <unordered_map>

int main()
{
    // std::unordered_map<char>

    std::string res = {};

    ssize_t k = 0;
    std::cin >> k;

    while (k - 1000 > 0) {
        res += 'M';
        k -= 1000;
    }
    while (k - 900 > 0) {
        res += "CM";
        k -= 900;
    }
    while (k - 500 > 0) {
        res += 'D';
        k -= 500;
    }
    while (k - 400 > 0) {
        res += "CD";
        k -= 400;
    }
    while (k - 100 > 0) {
        res += 'C';
        k -= 100;
    }
    while (k - 90 > 0) {
        res += "XC";
        k -= 90;
    }
    while (k - 50 > 0) {
        res += 'L';
        k -= 50;
    }
    while (k - 40 > 0) {
        res += "XL";
        k -= 40;
    }
    while (k - 10 > 0) {
        res += 'X';
        k -= 10;
    }
    while (k - 9 > 0) {
        res += "IX";
        k -= 9;
    }
    while (k - 5 > 0) {
        res += 'V';
        k -= 5;
    }
    while (k - 4 > 0) {
        res += "IV";
        k -= 4;
    }
    while (k > 0) {
        res += 'I';
        k--;
    }

    std::cout << res;
}
