#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int numIslands(vector<vector<string>> &grid)
    {
        set<pair<int, int>> visited;
        int                 islands = 0;

        auto find = [&](int col, int row) {
            auto isValidPos = [&](int col, int row) {
                return col >= 0 && col < grid.size() && row >= 0 && row < grid[0].size();
            };
            deque<pair<int, int>> deq;
            deq.push_back({col, row});

            while (!deq.empty()) {
                auto [col, row] = deq.front();
                deq.pop_front();

                if (!isValidPos(col, row))
                    continue;

                if (grid[col][row] == "1" && visited.find({col, row}) == visited.end()) {
                    visited.insert({col, row});
                    deq.insert(
                        deq.end(),
                        {{col + 1, row}, {col - 1, row}, {col, row + 1}, {col, row - 1}});
                }
            }
        };

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (visited.find({i, j}) == visited.end() && grid[i][j] == "1") {
                    islands++;
                    find(i, j);
                }

        return islands;
    }
};

int main()
{
    Solution sol;

    vector<vector<string>> grid = {{"1", "1", "1", "1", "0"},
                                   {"1", "1", "0", "1", "0"},
                                   {"1", "1", "0", "0", "0"},
                                   {"0", "0", "0", "0", "0"}};
    std::cout << sol.numIslands(grid) << '\n';

    return 0;
}
