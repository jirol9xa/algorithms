#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int begin = 0, end = matrix.size() - 1;
        while (begin < end) {
            int         mid = (begin + end + 1) / 2;
            const auto &row = matrix[mid];

            if (row[0] <= target)
                begin = mid;
            else
                end = mid - 1;
        }

        const auto &row = matrix[begin];
        if (row[row.size() - 1] < target)
            return false;

        begin = 0;
        end   = row.size() - 1;
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (row[mid] >= target)
                end = mid;
            else
                begin = mid + 1;
        }

        return row[begin] == target;
    }
};

int main()
{
    Solution            sol;
    vector<vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    std::cout << sol.searchMatrix(vec, 8) << '\n';

    return 0;
}
