#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//TODO：水位上升的泳池中游泳
class Solution
{
private:
    //并查集
    int *set;
    int waterLevel = 0;
    int findRoot(int x)
    {
        return x == set[x] ? x : findRoot(set[x]);
    }
    int visit(int x, int size, vector<vector<int>> &grid)
    {
        int i = x / size;
        int j = x % size;
        return grid[i][j];
    }
    bool checkContain(int x, int y, int size, vector<vector<int>> &grid)
    {
        if (visit(x, size, grid) <= waterLevel && visit(y, size, grid) <= waterLevel)
        {
            return true;
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = n * n;
        queue<int> start;
        queue<int> end;

        //初始化并查集
        set = new int[m];
        for (int i = 0; i < m; i++)
        {
            set[i] = i;
        }

        while (true)
        {

            for (int i = 0; i < m; i++)
            {
                int right = i + 1;
                int bottom = i + n;
                if (right / n == i / n && right < m && checkContain(i, right, n, grid))
                {
                    set[findRoot(right)] = findRoot(i);
                }
                if (bottom % n == i % n && bottom < m && checkContain(i, bottom, n, grid))
                {
                    set[findRoot(bottom)] = findRoot(i);
                }
                if (findRoot(0) == findRoot(m - 1))
                {
                    return waterLevel;
                }
            }

            waterLevel++;
        }
    }
};
class Solution1
{
private:
    //并查集
    int *set;
    int waterLevel = 0;
    int findRoot(int x)
    {
        return x == set[x] ? x : findRoot(set[x]);
    }
    int visit(int x, int size, vector<vector<int>> &grid)
    {
        int i = x / size;
        int j = x % size;
        return grid[i][j];
    }
    bool checkContain(int x, int y, int size, vector<vector<int>> &grid)
    {
        if (visit(x, size, grid) <= waterLevel && visit(y, size, grid) <= waterLevel)
        {
            return true;
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = n * n;
        queue<int> start;
        queue<int> end;

        //初始化并查集
        set = new int[m];
        for (int i = 0; i < m; i++)
        {
            set[i] = i;
        }

        start.push(0);
        end.push(m - 1);

        while (true)
        {

            int i = start.front();
            int right = i + 1;
            int bottom = i + n;
            bool ri;
            bool bo;
            if (ri = (right / n == i / n && right < m && checkContain(i, right, n, grid)))
            {
                set[findRoot(right)] = findRoot(i);
                start.push(right);
            }
            if (bo = (bottom % n == i % n && bottom < m && checkContain(i, bottom, n, grid)))
            {
                set[findRoot(bottom)] = findRoot(i);
                start.push(bottom);
            }
            if (findRoot(0) == findRoot(m - 1))
            {
                return waterLevel;
            }

            waterLevel++;
        }
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> grid{{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
    Solution solution;
    Solution1 solution1;
    int i = solution.swimInWater(grid);
    cout << i << endl;
    return i;
}