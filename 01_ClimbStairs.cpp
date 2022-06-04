// Climb stairs

// You are given the number of stairs you have to climb as n, in one step
// you are allowed to climb either 1 stair or 2 stairs.
// Return the number of possible ways to reach to nth stair if initially you
// are on the 0th stair.

#include <bits/stdc++.h>
using namespace std;

class Solution5
{
    // Tabulation : Bottoms UP : Optimised space 
public:
    int waysCount(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        int prev2 = 1, prev1 = 2, ans;
        for (int i = 3; i <= n; ++i)
        {
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};

class Solution4
{
    // Tabulation : Bottoms UP
public:
    int waysCount(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution3
{
    // Memoization method : Top down
public:
    int waysCount(int n)
    {
        vector<int> dp(n, -1);
        return solve(n - 1, dp) + solve(n - 2, dp);
    }
    int solve(int n, vector<int> &dp)
    {
        if (n <= 0)
        {
            if (0 == n)
            {
                return 1;
            }
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
};

class Solution2
{
    // Count the ways using sum
public:
    int waysCount(int n)
    {
        if (n <= 0)
        {
            if (0 == n)
            {
                return 1;
            }
            return 0;
        }
        return waysCount(n - 1) + waysCount(n - 2);
    }
};

class Solution1
{
    // recursion solution n as parameter
public:
    int waysCount(int n)
    {
        int count = 0;
        waysCount(n, count);
        return count;
    }
    void waysCount(int n, int &count)
    {
        if (n <= 0)
        {
            if (0 == n)
            {
                ++count;
            }
            return;
        }
        // Take one step
        waysCount(n - 1, count);
        // Take two step
        waysCount(n - 2, count);
    }
};

class Solution
{
    // Simple recursion solution
public:
    int waysCount(int n)
    {
        int count = 0;
        waysCount(n, count);
        return count;
    }
    void waysCount(int &n, int &count, int i = 0)
    {
        if (i >= n)
        {
            if (i == n)
            {
                ++count;
            }
            return;
        }
        // Take one step
        waysCount(n, count, i + 1);
        // Take two step
        waysCount(n, count, i + 2);
    }
};

int main()
{
    Solution5 obj1;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Possible ways : " << obj1.waysCount(n) << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}