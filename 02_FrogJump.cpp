// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// There is a frog on the 1st step of an N stairs long staircase.
// The frog wants to reach the Nth stair. HEIGHT[i] is the height
// of the (i+1)th stair.If Frog jumps from ith to jth stair, the
// energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
// In the Frog is on ith staircase, he can jump either to (i+1)th
// stair or to (i+2)th stair. Your task is to find the minimum total
// energy used by the frog to reach from 1st stair to Nth stair.

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // DP Solution : Tabulation (bottom up)
public:
    int frogJump(int n, vector<int> &heights)
    {
        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            int f = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int s = INT_MAX;
            if (i > 1)
            {
                s = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            }
            dp[i] = min(f, s);
        }
        return dp[n - 1];
    }
};

class Solution1
{
    // DP Solution : Memoization (Top down)
public:
    int solve(int n, vector<int> &heights, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int left = solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
        int right = INT_MAX;
        if (n > 1)
            right = solve(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
        return dp[n] = min(left, right);
    }
    int frogJump(int n, vector<int> &heights)
    {
        vector<int> dp(n, -1);
        return solve(n - 1, heights, dp);
    }
};

class Solution
{
public:
    int solve(int n, vector<int> &heights)
    {
        if (n == 0)
        {
            return 0;
        }
        int left = frogJump(n - 1, heights) + abs(heights[n] - heights[n - 1]);
        int right = INT_MAX;
        if (n > 1)
            right = frogJump(n - 2, heights) + abs(heights[n] - heights[n - 2]);
        return min(left, right);
    }
    int frogJump(int n, vector<int> &heights)
    {
        return solve(n - 1, heights);
    }
};

class Solution
{
    // Simple Recursion - Wrong answer
public:
    int frogJump(int n, vector<int> &heights)
    {
        int ans = INT_MAX, energy = 0;
        solve(n - 1, heights, ans, energy);
        return ans;
    }
    void solve(int n, vector<int> &heights, int &ans, int &energy)
    {
        if (n < 1)
        {
            if (n == 0)
            {
                ans = min(ans, energy);
            }
            return;
        }
        // Take one step
        energy += abs(heights[n] - heights[n - 1]);
        solve(n - 1, heights, ans, energy);
        energy -= abs(heights[n] - heights[n - 1]);
        // Take two step
        if (n > 1)
        {
            energy += abs(heights[n] - heights[n - 2]);
            solve(n - 2, heights, ans, energy);
        }
        else
        {
            return;
        }
    }
};

int main()
{
    vector<int> heights = {10, 20, 30, 10};
    Solution Obj1;
    cout << Obj1.frogJump(4, heights);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}