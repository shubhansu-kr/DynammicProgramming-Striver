// https://leetcode.com/problems/partition-equal-subset-sum/

// Given a non-empty array nums containing only positive integers,
// find if the array can be partitioned into two subsets such that
// the sum of elements in both subsets is equal.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursive solution : Memoization
public:
    bool canPartition(vector<int> &nums)
    {
        int right = 0, left = 0;
        for (int a : nums)
            right += a;
        vector<vector<int>> dp(nums.size(), vector<int>(right + 1, -1));
        return solve(nums, dp, left, right);
    }
    bool solve(vector<int> &nums, vector<vector<int>> &dp, int left, int right, int i = 0)
    {
        // Base condition
        if (left == right)
            return true;
        if (i == nums.size())
            return left == right;

        if (dp[i][left] != -1)
            return dp[i][left];
        // Take
        bool take = false;
        if (nums[i] + left <= right)
            take = solve(nums, dp, left + nums[i], right - nums[i], i + 1);

        if (take)
            return take;

        // noTake
        bool noTake = solve(nums, dp, left, right, i + 1);

        return dp[i][left] = (take || noTake);
    }
};

class Solution
{
    // Recursive solution : TLE
public:
    bool canPartition(vector<int> &nums)
    {
        int right = 0, left = 0;
        for (int a : nums)
            right += a;
        return solve(nums, left, right);
    }
    bool solve(vector<int> &nums, int left, int right, int i = 0)
    {
        // Base condition
        if (left == right)
            return true;
        if (i == nums.size())
            return left == right;

        // Take
        bool take = false;
        if (nums[i] + left <= right)
            take = solve(nums, left + nums[i], right - nums[i], i + 1);

        if (take)
            return take;

        // noTake
        bool noTake = solve(nums, left, right, i + 1);

        return (take || noTake);
    }
};

int main()
{
    vector<int> nums = {1, 9, 3, 5};

    Solution Obj1;
    cout << Obj1.canPartition(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}