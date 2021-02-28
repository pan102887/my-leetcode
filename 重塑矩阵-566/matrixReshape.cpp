#include <iostream>
#include <vector>
using namespace std;
class solution
{
private:
    int &visit(vector<vector<int>> &nums, int target)
    {
        int m = nums.size();
        int n = nums[0].size();

        int i = target / n;
        int j = target % n;

        return nums[i][j];
    }

public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> res(r, vector<int>(c));
        int m = nums.size();
        int n = nums[0].size();
        for (int i; i < m * n; i++)
        {
            visit(res, i) = visit(nums, i);
        }
        return res;
    }
};