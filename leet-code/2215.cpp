#include <iostream>
#include <vector>

using namespace std;

void VecPrinter(const vector<int> &vec)
{
    for (auto &&elem : vec) {
        std::cout << elem << ' ';
    }
}

void VecsPrinter(const vector<vector<int>> &vecs)
{
    for (auto &&vec : vecs) {
        std::cout << '[';
        VecPrinter(vec);
        std::cout << "], ";
    }
}

class Solution {
    void sortVec(int begin, int end, vector<int> &vec)
    {
        if (begin == end)
            return;

        int left = begin, right = end;
        int pivot = vec[(begin + end) / 2];

        while (right >= left) {
            while (vec[left] < pivot)
                ++left;
            while (vec[right] > pivot)
                --right;

            if (left <= right)
                std::swap(vec[left++], vec[right--]);
        }

        if (left < end)
            sortVec(left, end, vec);
        if (right > begin)
            sortVec(begin, right, vec);
    }

  public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> diff1, diff2;

        sortVec(0, nums1.size() - 1, nums1);
        sortVec(0, nums2.size() - 1, nums2);

        int i = 0, j = 0;
        for (; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] < nums2[j]) {
                auto elem = nums1[i++];
                diff1.push_back(elem);
                while (i < nums1.size() && nums1[i] == elem)
                    ++i;
            }
            else if (nums2[j] < nums1[i]) {
                auto elem = nums2[j++];
                diff2.push_back(elem);

                while (j < nums2.size() && nums2[j] == elem)
                    ++j;
            }
            else {
                auto elem = nums1[i++];
                ++j;
                while (j < nums2.size() && nums2[j] == elem)
                    ++j;
                while (i < nums1.size() && nums1[i] == elem)
                    ++i;
            }
        }

        VecPrinter(nums1);
        std::cout << '\n';
        VecPrinter(nums2);
        std::cout << '\n';

        for (; i < nums1.size();) {
            auto elem = nums1[i++];
            diff1.push_back(elem);
            while (i < nums1.size() && nums1[i] == elem)
                ++i;
        }
        for (; j < nums2.size();) {
            auto elem = nums2[j++];
            diff2.push_back(elem);
            while (j < nums2.size() && nums2[j] == elem)
                ++j;
        }

        return {diff1, diff2};
    }
};

int main()
{
    Solution    sol;
    vector<int> first = {26, 48, -78, -25, 42, -8, 94, -68, 26}, second = {61, -17};

    VecsPrinter(sol.findDifference(first, second));

    return 0;
}
