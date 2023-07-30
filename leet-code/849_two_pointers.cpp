#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxDistToClosest(vector<int> &seats)
    {
        int seats_amnt = seats.size();

        int most_left = 0;
        for (int i = 0; i < seats_amnt; ++i)
            if (seats[i]) {
                most_left = i;
                break;
            }

        if (most_left == seats_amnt - 1)
            return most_left;

        int most_right = 0;
        for (int i = seats_amnt - 1; i >= most_left; --i)
            if (seats[i]) {
                most_right = i;
                break;
            }

        if (most_right == most_left)
            return std::max(most_left, seats_amnt - 1 - most_right);

        // We have more, than 2 personas
        int max_dist    = most_left;
        int last_person = most_left;
        for (int i = most_left + 1; i <= most_right; ++i) {
            if (seats[i]) {
                max_dist    = std::max(max_dist, i - last_person);
                last_person = i;
            }
        }

        return std::max(std::max(max_dist / 2, most_left), seats_amnt - 1 - most_right);
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {1, 0, 1};

    for (auto &&elem : vec)
        cout << elem << ' ';

    std::cout << sol.maxDistToClosest(vec) << '\n';

    return 0;
}
