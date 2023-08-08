#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    bool vecComp(const vector<int> &vec1, const vector<int> &vec2) const
    {
        if (vec1.size() != vec2.size())
            return false;

        for (int i = 0; i < vec1.size(); ++i)
            if (vec1[i] != vec2[i])
                return false;

        return true;
    }

  public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, vector<int>> syms_positions1;
        for (int i = 0; i < s.size(); ++i)
            syms_positions1[s[i]].push_back(i);

        unordered_map<char, vector<int>> syms_positions2;
        for (int i = 0; i < t.size(); ++i)
            syms_positions2[t[i]].push_back(i);

        for (int i = 'a'; i <= 'z'; ++i) {
            if (!vecComp(syms_positions1[i], syms_positions2[i]))
                return false;
        }

        return true;
#if 0
        for (int i = 0; i < s.size(); ++i) {
            auto sym = t[i];
            auto positions = syms_positions1[s[i]];
            for (auto &&pos : positions)
                if (t[pos] != sym)
                    return false;
        }
#endif

        return true;
    }
};

int main()
{
    Solution sol;
    string   s = "badc", t = "bada";

    std::cout << sol.isIsomorphic(s, t);

    return 0;
}
