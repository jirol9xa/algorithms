#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                             vector<vector<int>> &secondList)
    {
        vector<vector<int>> res = {};

        for (int i = 0, j = 0; j < secondList.size() && i < firstList.size();) {
            vector<int> intersec;

            const auto &elem1 = firstList[i];
            const auto &elem2 = secondList[j];

            if (elem1[0] >= elem2[0] && elem1[0] <= elem2[1])
                intersec.push_back(elem1[0]);
            else if (elem2[0] >= elem1[0] && elem2[0] <= elem1[1])
                intersec.push_back(elem2[0]);
            else
                goto next_list;

            intersec.push_back(std::min(elem1[1], elem2[1]));
            res.push_back(intersec);

        next_list:
            if (elem2[1] < elem1[1])
                ++j;
            else
                ++i;
        }

        return res;
    }
};

int main() { return 0; }
