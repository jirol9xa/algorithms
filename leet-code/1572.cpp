#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int res = 0;
        for (int i = 0; i < mat.size(); ++i)
            res += mat[i][i] + mat[i][mat.size() - 1 - i];

        return res - (mat.size() % 2) * mat[mat.size() / 2][mat.size() / 2];
    }
};

int main()
{
    Solution            sol;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << sol.diagonalSum(mat) << '\n';

    return 0;
}
