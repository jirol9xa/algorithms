#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;

        for (auto &elem : strs) {
            string tmp = elem;
            std::sort(tmp.begin(), tmp.end());
            map[tmp].push_back(elem);
        }

        vector<vector<string>> res;
        for (auto &&[_, vec] : map)
            res.push_back(vec);

        return res;
    }
};

int main() { return 0; }
