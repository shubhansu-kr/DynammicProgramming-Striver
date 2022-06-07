// FrogJump III

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Tabulation
public:
    int frogJump(int n, vector<int> &heights, int k)
    {
        vector<int> dp(n);
        for (int i = 1; i < n; ++i)
        {
            int subMin = INT_MAX;
            for (int j = 1; j <= k; ++j)
            {
                int f = INT_MAX;
                if (i >= j) {
                    f = dp[i-j] + abs(heights[i]-heights[i-j]);
                }
                subMin = min(f, subMin);
            }
            dp[i] = subMin;
        }
        return dp[n-1];
    }
};

class Solution1
{
    // Memoization (Top down)
public:
    int frogJump(int n, vector<int> &heights, int k)
    {
        vector<int> dp(n, -1);
        return dp[n-1] = solve(n - 1, heights, k, dp);
    }
    int solve(int n, vector<int> &heights, int &k, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int subMin = INT_MAX;
        for (int i = 1; i <= k; ++i)
        {
            int f = INT_MAX;
            if (n >= i)
            {
                f = solve(n - i, heights, k, dp) + abs(heights[n] - heights[n - i]);
            }
            subMin = min(subMin, f);
        }
        return dp[n] = subMin;
    }
};

class Solution
{
    // Simple recursion 
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
    Solution2 Obj1;
    cout << Obj1.frogJump(4, heights, 2);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}