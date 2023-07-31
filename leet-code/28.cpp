#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack.size(); ++i) {
            while (i < haystack.size() && haystack[i] != needle[0])
                ++i;

            int k = i;
            int j = 0;
            for (; j < needle.size() && k < haystack.size() && needle[j] == haystack[k];
                 ++j, ++k)
                continue;

            if (j == needle.size())
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    string str1 = "mississippi", str2 = "issip";

    std::cout << sol.strStr(str1, str2) << '\n';

    return 0;
}
