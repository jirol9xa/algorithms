class Solution {
  public:
    int climbStairs(int n)
    {
        if (n < 3)
            return n;

        int prev = 3, prev_prev = 2;

        for (int i = 3; i < n; ++i) {
            int tmp = prev;
            prev += prev_prev;
            prev_prev = tmp;
        }

        return prev;
    }
};
