#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char **)
{
    Solution2 solution;
}


class Solution2
{
public:
    string t;
    vector<string> ans;

    vector<string> subsets(string& str){
        int n = str.size();
        for(int mask = 0; mask < (1 << n); mask++){
            for(int i = 0; i < n; i++){
                t.clear();
                if(mask & (1 << i)){
                    t.push_back(str[i]);
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};