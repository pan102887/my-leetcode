#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static int stepCount(int length, int a[])
    {
        int *step = new int[length];
        bool *pre = new bool[length];
        bool modify = false;
        for (int i = 0; i < length; i++)
        {
            pre[i] = false;
        }

        step[0] = 0;
        for (int i = 1; i < length; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (j != i - 1 && a[i] == a[j])
                {
                    int temp;
                    if (!pre[j])
                    {
                        temp = step[j] + 1;
                    }
                    else
                    {
                        temp = step[j];
                    }
                    if (temp < step[i - 1])
                    {
                        step[i] = temp;
                        pre[i] = true;
                    }
                    else
                    {
                        step[i] = step[i - 1] + 1;
                    }
                    modify = true;
                }
                if (!modify)
                {
                    step[i] = step[i - 1] + 1;
                }
            }
        }
        return step[length - 2];
    }
};

int main()
{
    //int length;
    //int* arr;
    //cin >> length;
    //arr = new int[length];
    //for (int i = 0; i < length; i++) {
    //	cin >> arr[i];
    //}
    //Solution a;
    int arr[11] = {0, 1, 2, 1, 1, 1, 3, 4, 7, 2, 5};

    Solution a;
    int step = a.stepCount(11, arr);
    cout << step << endl;
}

/*
	思路：第i个位置的上一个位置可以为i-1或者离i最近的一个与第i个位置相同的数的位置
*/