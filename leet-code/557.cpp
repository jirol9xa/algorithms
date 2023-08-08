#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    void swapLetters(int first, int last, string &str)
    {
        while (first < last)
            std::swap(str[first++], str[last--]);
    }

    string reverseWords(string &s)
    {
        int first_sym = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (first_sym == -1 && !isspace(s[i])) {
                first_sym = i;
            }
            else if (first_sym != -1 && isspace(s[i])) {
                swapLetters(first_sym, i - 1, s);
                first_sym = -1;
            }
        }

        if (first_sym != -1)
            swapLetters(first_sym, s.size() - 1, s);

        return s;
    }
};

int main()
{
    Solution sol;

    string str = "";

    std::cout << sol.reverseWords(str);

    return 0;
}
