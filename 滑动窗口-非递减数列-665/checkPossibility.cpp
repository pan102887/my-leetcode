#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        bool modifidable = true;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && nums[i] > nums[i + 1])
            {
                if (modifidable)
                {
                    modifidable = false;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};