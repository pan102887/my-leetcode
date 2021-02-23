#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        int n = customers.size();
        int m = grumpy.size();

        int temp = 0;
        int max = 0;
        int sum = 0;
        if (n == m)
        {
            for (int i = 0; i < n; i++)
            {
                if (grumpy[i] == 0)
                {
                    sum += customers[i];
                }
                grumpy[i] = grumpy[i] * customers[i];
            }
            for (int i = 0; i < n; i++)
            {
                if (i >= X)
                {
                    temp -= grumpy[i - X];
                }
                temp += grumpy[i];
                if (i >= X - 1 && temp > max)
                {
                    max = temp;
                }
            }
        }
        return sum + max;
    }
};
class Solution1
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        int total = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
            {
                total += customers[i];
            }
        }
        int increase = 0;
        for (int i = 0; i < X; i++)
        {
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        for (int i = X; i < n; i++)
        {
            increase = increase - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
            maxIncrease = max(maxIncrease, increase);
        }
        return total + maxIncrease;
    }
};

int main(int argc, char **argv)
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;
    Solution solution;

    int res = solution.maxSatisfied(customers, grumpy, X);
    return 0;
}