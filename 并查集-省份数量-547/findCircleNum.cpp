#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int *set;
    int findRoot(int x)
    {
        return set[x] == x ? x : findRoot(set[x]);
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected[0].size();

        set = new int[n];
        for (int i = 0; i < n; i++)
        {
            set[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isConnected[i][j] && findRoot(i) != findRoot(j))
                {
                    set[findRoot(j)] = findRoot(i);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (set[i] == i)
                result++;
        }
        return result;
    }
};