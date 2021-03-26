#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int size = nums.size();
        int min_left = nums[0];
        for (int j = 1; j < size - 1; j++)
        {
            if (nums[j] > min_left)
            {
                for (int k = j + 1; k < size; k++)
                {
                    if (nums[k] < nums[j] && nums[k] > min_left)
                    {
                        return true;
                    }
                }
            }
            if (nums[j] < min_left)
                min_left = nums[j];
        }
        return false;
    }
    bool find132pattern_1(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        // 左侧最小值
        int left_min = nums[0];
        // 右侧所有元素
        //multiset 是一个有序的序列，插入和删除都能在O(logn)的时间复杂度内玩长城
        multiset<int> right_all;

        for (int k = 2; k < n; ++k) {
            right_all.insert(nums[k]);
        }

        for (int j = 1; j < n - 1; ++j) {
            if (left_min < nums[j]) {
                //upper_bound: 返回第一个比"left_min"大的元素指针，若没有则返回end指针
                auto it = right_all.upper_bound(left_min);
                if (it != right_all.end() && *it < nums[j]) {
                    return true;
                }
            }
            left_min = min(left_min, nums[j]);
            right_all.erase(right_all.find(nums[j + 1]));
        }

        return false;
    }

};