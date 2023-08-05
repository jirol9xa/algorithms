#include <iostream>
#include <string>

void printCoins(int amnt, int val, std::string &s)
{
    if (!amnt)
        return;

    for (int i = 0; i < amnt; ++i)
        s += std::to_string(val) + ' ';
}

int main()
{
    long money = 0;
    std::cin >> money;

    int coins[5];

    coins[4] = money / 50;
    money %= 50;
    coins[3] = money / 20;
    money %= 20;
    coins[2] = money / 10;
    money %= 10;
    coins[1] = money / 5;
    money %= 5;
    coins[0] = money;

    std::cout << coins[0] + coins[1] + coins[2] + coins[3] + coins[4] << '\n';
    std::string str;
    printCoins(coins[4], 50, str);
    printCoins(coins[3], 20, str);
    printCoins(coins[2], 10, str);
    printCoins(coins[1], 5, str);
    printCoins(coins[0], 1, str);

    if (str[str.length() - 1] == ' ')
        str[str.length() - 1] = '\0';

    std::cout << str;

    return 0;
}
