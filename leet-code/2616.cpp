#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void sort(int begin, int end, vector<int> &vec)
    {
        if (begin == end)
            return;

        int right = end, left = begin;
        int pivot = vec[(begin + end) / 2];

        while (left <= right) {
            while (vec[left] < pivot)
                ++left;
            while (vec[right] > pivot)
                --right;

            if (left >= right)
                std::swap(vec[left++], vec[right--]);
        }

        if (right > begin)
            sort(begin, right, vec);
        if (left < end)
            sort(left, end, vec);
    }

  public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(0, nums.size() - 1, nums);

        // TODO:
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {};

    std::cout << sol.minimizeMax(vec);

    return 0;
}
