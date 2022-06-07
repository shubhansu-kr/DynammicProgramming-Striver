// FrogJump III

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Solution 1 : Simple recursion 
public:
    int frogJump(int n, vector<int> &heights, int k)
    {
        return solve(n - 1, heights, k);
    }
    int solve(int n, vector<int> &heights, int &k)
    {
        if (n == 0)
        {
            return 0;
        }
        int subMin = INT_MAX;
        for (int i = 1; i <= k; ++i)
        {
            int f = INT_MAX;
            if (n >= i)
            {
                f = solve(n - i, heights, k) + abs(heights[n] - heights[n - i]);
            }
            subMin = min(subMin, f);
        }
        return subMin;
    }
};

int main()
{
    vector<int> heights = {10, 20, 30, 10};
    Solution Obj1;
    cout << Obj1.frogJump(4, heights, 2);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}