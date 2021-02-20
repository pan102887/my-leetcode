#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> map;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (map.count(nums[i]))
            {
                map[nums[i]][0]++;
                map[nums[i]][2] = i;
            }
            else
            {
                map[nums[i]] = {1, i, i};
            }
        }
        int maxFreq = 0, minLen = 0;
        for (auto &[_, vec] : map)
        {
            if (maxFreq < vec[0])
            {
                maxFreq = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if (maxFreq == vec[0])
            {
                if (minLen > vec[2] - vec[1] + 1)
                {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};
int main(int argc, char *argv[])
{
    return 0;
}