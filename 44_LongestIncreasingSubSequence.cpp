// https://leetcode.com/problems/longest-increasing-subsequence/

// Given an integer array nums, return the length of the longest
// strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by
// deleting some or no elements without changing the order of the
// remaining elements. For example, [3,6,2,7] is a subsequence of
// the array [0,3,1,6,2,2,7].

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Wrong Solution : Runtime error 
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                int pick = -1e9;
                if (j == 0 || nums[j] > nums[i-1]) {pick = 1 + dp[i-1][i];}
                int noPick = dp[i-1][j];
                dp[i][j+1] = max(pick, noPick);
            }
        }
        return dp[n][0];
    }
};

class Solution2
{
    // Recursion: Memoization  
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, dp, n-1);
    }
    int solve(vector<int> &nums, vector<vector<int>> &dp, int i, int j = -1)
    {
        if (i == -1) return 0;
        if (dp[i][j+1] != -1) return dp[i][j+1];
        int pick = -1e9;
        if (j == -1 || nums[j] > nums[i]) {pick = 1 + solve(nums, dp, i-1, i);}
        int noPick = solve(nums, dp, i-1, j);
        return dp[i][j+1] = max(pick, noPick);
    }
};

class Solution1
{
    // BruteForce: Recursion 
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n-1);
    }
    int solve(vector<int> &nums, int i, int j = -1)
    {
        if (i == -1) return 0;
        int pick = -1e9;
        if (j == -1 || nums[j] > nums[i]) {pick = 1 + solve(nums, i-1, i);}
        int noPick = solve(nums, i-1, j);
        return max(pick, noPick);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int lengthOfLIS(vector<int> &nums)
    {
        return solve(nums);
    }
    int solve(vector<int> &nums, int prev = INT_MIN, int i = 0)
    {
        if (i == nums.size())
            return 0;

        int pick = -1e9;
        if (nums[i] > prev)
        {
            pick = 1 + solve(nums, nums[i], i + 1);
        }
        int noPick = solve(nums, prev, i + 1);

        return max(pick, noPick);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}