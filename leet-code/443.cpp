#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int compress(vector<char> &chars)
    {
        if (chars.size() == 1)
            return 1;

        char prev_sym               = chars[0];
        int  curr_amnt              = 1;
        int  pos_in_chars_for_write = 1;

        auto write_number = [&]() {
            for (auto &&sym : to_string(curr_amnt))
                chars[pos_in_chars_for_write++] = sym;
        };

        for (long i = 1; i < chars.size(); ++i) {
            if (chars[i] == prev_sym) {
                ++curr_amnt;
                continue;
            }

            if (curr_amnt > 1)
                write_number();
            chars[pos_in_chars_for_write++] = chars[i];
            prev_sym                        = chars[i];
            curr_amnt                       = 1;
        }

        if (curr_amnt > 1)
            write_number();

        return pos_in_chars_for_write;
    }
};

int main()
{
    Solution     sol;
    vector<char> vec = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int res = sol.compress(vec);
    std::cout << res << '\n';
    for (int i = 0; i < res; ++i)
        std::cout << vec[i] << ' ';
    std::puts("\n");

    return 0;
}
