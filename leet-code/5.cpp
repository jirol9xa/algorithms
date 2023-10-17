#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string longestPalindrome(string s)
    {
        size_t res_begin = 0, res_length = 1;
        for (size_t i = 0; i < s.size(); ++i) {
            // odd length palindrome
            {
                for (ssize_t begin = i, end = i;
                     begin >= 0 && end < s.size() && s[begin] == s[end]; --begin, ++end)
                    if ((end - begin + 1) > res_length) {
                        res_begin  = begin;
                        res_length = end - begin + 1;
                    }
            }

            // even length
            {
                for (ssize_t begin = i, end = i + 1;
                     begin >= 0 && end < s.size() && s[begin] == s[end]; --begin, ++end)
                    if ((end - begin + 1) > res_length) {
                        res_begin  = begin;
                        res_length = end - begin + 1;
                    }
            }
        }

        return s.substr(res_begin, res_length);
    }
};

int main()
{
    Solution sol;
    std::cout << sol.longestPalindrome("babad") << '\n';

    return 0;
}
