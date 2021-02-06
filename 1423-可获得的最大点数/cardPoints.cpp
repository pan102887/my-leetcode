#include <iostream>
#include <vector>
using namespace std;

class CardPoints
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int count = 0;
        int sum = 0;
        long int max = INT32_MIN;
        int n = cardPoints.size();

        for (int i = n - k; i <= n + k - 1; i++)
        {
            if (count >= k)
            {
                sum -= cardPoints[(i - k) % n];
            }
            sum += cardPoints[i % n];
            count++;
            if (count >= k && sum > max)
            {
                max = sum;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> card{1,2,1};
    int k = 1;
    CardPoints a;
    int max = a.maxScore(card, k);
    cout << max;
}