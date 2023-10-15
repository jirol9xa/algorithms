#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<char>   par;
    vector<string> res;
    int            n = 0;

    void backtrack(int open_num, int close_num)
    {
        if (open_num == close_num && open_num == n) {
            string str_res;
            for (auto &&elem : par)
                str_res += elem;

            res.push_back(str_res);
            return;
        }

        if (open_num < n) {
            par.push_back('(');
            backtrack(open_num + 1, close_num);
            par.pop_back();
        }

        if (close_num < open_num) {
            par.push_back(')');
            backtrack(open_num, close_num + 1);
            par.pop_back();
        }
    };

    vector<string> generateParenthesis(int n)
    {
        this->n = n;
        backtrack(0, 0);

        return res;
    }
};

int main()
{
    Solution sol;
    auto     res = sol.generateParenthesis(3);

    for (auto &&elem : res)
        std::cout << elem << ' ';
    std::puts("\n");

    return 0;
}
