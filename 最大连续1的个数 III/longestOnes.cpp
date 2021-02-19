#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int n = A.size();
        vector<int> P(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            P[i] = P[i - 1] + (1 - A[i - 1]);
        }

        int ans = 0;
        for (int right = 0; right < n; ++right)
        {
            int left = lower_bound(P.begin(), P.end(), P[right + 1] - K) - P.begin();
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    int longestOnes_2(vector<int> &A, int K)
    {
        int n = A.size();
        int left = 0, lsum = 0, rsum = 0;
        int ans = 0;
        for (int right = 0; right < n; ++right)
        {
            rsum += 1 - A[right];
            while (lsum < rsum - K)
            {
                lsum += 1 - A[left];
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
int main(int argc, char **argv)
{
    vector<int> A = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    Solution solution;
    int res = solution.longestOnes(A, k);
    cout << res << endl;
    return 0;
}