#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    struct Hash {
        int operator()(const string &arg) {
            uint64_t hash = 0;
            std::hash<char> hash_obj;
            for (auto sym : arg) {
                printf("sym = %d, ", sym);
                std::cout << "hash = " << hash_obj(sym) << '\n';
                hash += hash_obj(sym);
            }

            return hash;
        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<uint64_t, vector<string>> map;
        Hash hash;
        vector<vector<string>> res;

        for (auto &&str : strs)
            map[hash(str)].push_back(str);

        for (auto &&[_, vec] : map)
            res.push_back(vec);

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> vec = {"eat","tea","tan","ate","nat","bat"};

    auto res = sol.groupAnagrams(vec);
    for (auto &&vec_res : res) {
        std::cout << "[";
        for (auto &&str : vec_res)
            std::cout << '\"'<< str << "\", ";
        std::cout << "],";
    }

    std::cout << '\n';

    return 0;
}
