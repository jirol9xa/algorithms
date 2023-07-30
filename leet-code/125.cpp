#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s)
    {
        int size = s.size();
        if (size <= 1)
            return true;

        for (int i = 0, j = size - 1; i < j; i++, j--) {
            while (!isalnum(s[i]) && i < j)
                ++i;
            while (!isalnum(s[j]) && i < j)
                --j;
            if (i == j)
                return true;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string   str = "....";

    cout << sol.isPalindrome(str) << '\n';

    return 0;
}
