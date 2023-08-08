#include <iostream>
#include <string>

using namespace std;

class Solution {
  private:
    void sortStr(int begin, int end, string &str)
    {
        if (begin == end)
            return;

        int left = begin, right = end;
        int pivot = str[(begin + end) / 2];

        while (right >= left) {
            while (str[left] < pivot)
                ++left;
            while (str[right] > pivot)
                --right;

            if (left <= right)
                std::swap(str[left++], str[right--]);
        }

        if (left < end)
            sortStr(left, end, str);
        if (right > begin)
            sortStr(begin, right, str);
    }

  public:
    bool isAnagram(string &s, string &t)
    {
        if (s.size() != t.size())
            return false;

        sortStr(0, s.size() - 1, s);
        sortStr(0, t.size() - 1, t);

        for (int i = 0; i < s.size(); ++i)
            if (s[i] != t[i])
                return false;

        return true;
    }
};

int main() { return 0; }
