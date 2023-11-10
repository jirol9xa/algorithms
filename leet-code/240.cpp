#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(const vector<vector<int>> &matrix, int target)
    {
        int begin = 0, end = matrix.size() - 1;
        while (begin < end) {
            int mid = (begin + end + 1) / 2;
            if (matrix[mid][0] <= target)
                begin = mid;
            else
                end = mid - 1;
        }

        // begin now contains max row number
        for (int i = 0; i <= begin; ++i) {
            int begin1 = 0, end1 = matrix[i].size() - 1;
            while (begin1 < end1) {
                int mid = (begin1 + end1) / 2;
                if (matrix[i][mid] >= target)
                    end1 = mid;
                else
                    begin1 = mid + 1;
            }

            if (matrix[i][begin1] == target)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.searchMatrix({{1, 4, 7, 11, 15},
                                   {2, 5, 8, 12, 19},
                                   {3, 6, 9, 16, 22},
                                   {10, 13, 14, 17, 24},
                                   {18, 21, 23, 26, 30}},
                                  20)
              << '\n';
    return 0;
}
