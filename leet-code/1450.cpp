#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int res = 0;
        for (int i = 0; i < startTime.size(); ++i)
            res += queryTime >= startTime[i] && queryTime <= endTime[i];

        return res;
    }
};

int main() { return 0; }
