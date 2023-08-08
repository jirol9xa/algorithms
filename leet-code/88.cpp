#include <iostream>
#include <vector>

using namespace std;

void VecPrinter(const std::vector<int> &vec)
{
    for (auto &&elem : vec)
        std::cout << elem << ' ';
    std::cout << '\n';
}

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = n + m - 1, j = n - 1, k = m - 1;
        for (; i >= 0 && j >= 0 && k >= 0; i--) {
            if (nums1[k] > nums2[j]) {
                nums1[i] = nums1[k];
                k--;
            }
            else {
                nums1[i] = nums2[j];
                j--;
            }
        }

        if (j < 0)
            return;

        for (; j >= 0; --j, --i)
            nums1[i] = nums2[j];
    }
};

int main()
{
    Solution         sol;
    std::vector<int> vec1 = {7, 8, 9, 0, 0, 0};
    std::vector<int> vec2 = {1, 8, 8};

    sol.merge(vec1, 3, vec2, 3);

    VecPrinter(vec1);

    return 0;
}
