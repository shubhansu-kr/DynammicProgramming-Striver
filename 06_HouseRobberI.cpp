// https://leetcode.com/problems/house-robber/

// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint
// stopping you from robbing each of them is that adjacent houses have security
// systems connected and it will automatically contact the police if two adjacent
// houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Recursive Solution : Tabulation (Space Optimised)
public:
    int rob(vector<int> &nums)
    {
        int prev=nums[0], prev1 = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            int p = nums[i] + prev1;
            prev1 = prev;
            prev = max(p, prev);
        }
        return prev;
    }
};

class Solution3
{
    // Recursive Solution : Tabulation
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            int p = nums[i] + ((i > 1) ? dp[i - 2] : 0);
            int x = dp[i - 1];
            dp[i] = max(p, x);
        }
        return dp[n - 1];
    }
};

class Solution2
{
    // Recursive Solution : Memoization
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dp[n - 1] = solve(nums, dp, n - 1);
    }
    int solve(vector<int> &nums, vector<int> &dp, int n)
    {
        if (n < 0)
        {
            return 0;
        }
        if (dp[n] != -1)
            return dp[n];
        int p = nums[n] + solve(nums, dp, n - 2);
        int x = solve(nums, dp, n - 1);
        return dp[n] = max(p, x);
    }
};

class Solution1
{
    // Recursive Solution Improved
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n - 1);
    }
    int solve(vector<int> &nums, int n)
    {
        if (n < 0)
        {
            return 0;
        }
        int p = nums[n] + solve(nums, n - 2);
        int x = solve(nums, n - 1);
        return max(p, x);
    }
};

class Solution
{
    // Recursive Solution
public:
    int rob(vector<int> &nums)
    {
        int ans = INT_MIN, sum = 0, n = nums.size();
        solve(nums, sum, ans, n - 1);
        return ans;
    }
    void solve(vector<int> &nums, int &sum, int &ans, int n)
    {
        if (n < 0)
        {
            ans = max(ans, sum);
            return;
        }
        // l -> Not picked
        // r -> picked

        sum += nums[n];
        solve(nums, sum, ans, n - 2);
        sum -= nums[n];
        solve(nums, sum, ans, n - 1);
    }
};

int main()
{
    vector<int> nums = {3, 4, 2};

    Solution2 Obj1;
    cout << Obj1.rob(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}