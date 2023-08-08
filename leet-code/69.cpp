class Solution {
  public:
    int mySqrt(int x)
    {
        int       upper_bound = 0;
        long long i           = 0;
        for (; i <= x; ++i) {
            if (i * i > x)
                break;

            upper_bound = i;
        }

        return upper_bound;
    }
};
