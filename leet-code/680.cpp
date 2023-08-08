#include <iostream>
#include <string>

using namespace std;

void printSyms(string &str, int start, int end)
{
    if (start < end)
        for (int i = start; i < end; ++i)
            std::cout << str[i] << ' ';
    else
        for (int i = start; i >= end; --i)
            std::cout << str[i] << ' ';

    std::cout << '\n';
}

class Solution {
  public:
    bool validPalindrome(const string &s, bool can_remove = true)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                if (s[i + 1] == s[j] && s[j - 1] == s[i] && can_remove)
                    return validPalindrome(s.substr(i, j - i), false) ||
                           validPalindrome(s.substr(i + 1, j - i), false);
                else if (s[i + 1] == s[j] && can_remove)
                    ++i;
                else if (s[j - 1] == s[i] && can_remove)
                    --j;
                else
                    return false;

                can_remove = false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string str = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfd"
                 "hooxfuupuculmgmqfvnbgtapekouga";

    std::cout << sol.validPalindrome(str) << '\n';

    return 0;
}
