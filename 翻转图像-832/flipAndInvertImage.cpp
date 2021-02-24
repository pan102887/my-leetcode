#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void reverse(vector<int> &a)
    {
        int n = a.size();
        int m = n / 2;
        int end = n - 1;
        int temp;
        for (int i = 0; i < m; i++)
        {
            if (a[i] == a[end - i])
            {
                switch (a[i])
                {
                case 0:
                    a[i] = 1;
                    a[end - i] = 1;
                    break;
                case 1:
                    a[i] = 0;
                    a[end - i] = 0;
                    break;
                default:
                    break;
                }
            }
        }
        if (n % 2 == 1)
        {
            switch (a[m])
            {
            case 0:
                a[m] = 1;
                break;
            case 1:
                a[m] = 0;
                break;
            }
        }
    }

public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int m = A.size();
        for (int i = 0; i < m; i++)
        {
            reverse(A[i]);
        }
        return A;
    }
};