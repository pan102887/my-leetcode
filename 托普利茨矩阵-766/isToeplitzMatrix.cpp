#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<bool>> visited;
    bool check(int i, int j, vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if (i < m - 1 && j < n - 1)
        {
            return (matrix[i][j] == matrix[i + 1][j + 1]) && check(i + 1, j + 1, matrix);
        }
        return true;
    }

    // bool check_1(int i, int j, vector<vector<int>> &matrix)
    // {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     this->visited.resize(m, vector<bool>(n, false));
    //     if (i == 0 || j == 0)
    //     {
    //         visited[i][j] = true;
    //     }
    //     if ((i > 0 && j > 0) && (i < m && j < n))
    //     {
    //         if (visited[i - 1][j - 1] && matrix[i][j] == matrix[i - 1][j - 1])
    //         {
    //             visited[i][j] = true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = m - 2; i >= 0; i--)
        {
            if (!check(i, 0, matrix))
                return false;
        }
        for (int j = 1; j < n - 1; j++)
        {
            if (!check(0, j, matrix))
                return false;
        }
        return true;
    }
};