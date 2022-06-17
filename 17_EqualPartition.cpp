// https://leetcode.com/problems/partition-equal-subset-sum/

// Given a non-empty array nums containing only positive integers,
// find if the array can be partitioned into two subsets such that
// the sum of elements in both subsets is equal.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Tabulation

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int a : nums)
            sum += a;
        if (sum % 2 != 0)
            return false;

        int k = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; ++i)
            dp[i][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];
                dp[i][j] = (take || notTake);
            }
        }
        return dp[n - 1][k];
    }
};

class Solution3
{
    // Recursion Optimised : Memoization

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int a : nums)
            sum += a;
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
        return (sum % 2) ? false : solve(nums, dp, sum / 2, n - 1);
    }

    bool solve(vector<int> &nums, vector<vector<int>> &dp, int k, int i)
    {
        if (k == 0)
            return true;
        if (i == 0)
            return k == nums[i];

        if (dp[i][k] != -1)
            return dp[i][k];

        // Pick
        bool pick = false;
        if (nums[i] <= k)
            pick = solve(nums, dp, k - nums[i], i - 1);
        if (pick)
            return pick;
        // NotPick
        bool noPick = solve(nums, dp, k, i - 1);

        return dp[i][k] = (pick || noPick);
    }
};

class Solution2
{
    // Recursion Optimised :

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int a : nums)
            sum += a;
        return (sum % 2) ? false : solve(nums, sum / 2, n - 1);
    }

    bool solve(vector<int> &nums, int k, int i)
    {
        if (k == 0)
            return true;
        if (i == 0)
            return k == nums[i];

        // Pick
        bool pick = false;
        if (nums[i] <= k)
            pick = solve(nums, k - nums[i], i - 1);
        if (pick)
            return pick;
        // NotPick
        bool noPick = solve(nums, k, i - 1);

        return (pick || noPick);
    }
};

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

    Solution2 Obj1;
    cout << Obj1.canPartition(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}