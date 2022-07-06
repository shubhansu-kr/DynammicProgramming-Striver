// https://leetcode.com/problems/target-sum/

// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the
// symbols '+' and '-' before each integer in nums and then concatenate
// all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-'
// before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which
// evaluates to target.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Recursion : subset Sum : Memoization
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sumNums = accumulate(nums.begin(), nums.end(), 0);
        target = (sumNums + target) / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(nums, dp, target, n - 1);
    }
    int solve(vector<int> nums, vector<vector<int>> &dp, int target, int i)
    {
        if (i == 0)
            return nums[i] == target;
        if (target == 0)
            return 1;

        if (dp[i][target] != -1)
            return dp[i][target];

        // Pick : Dont pick if nums[i] > target
        int p = 0;
        if (nums[i] <= target)
            p = solve(nums, dp, target - nums[i], i - 1);
        // noPick
        int np = solve(nums, dp, target, i - 1);

        return dp[i][target] = p + np;
    }
};

class Solution2
{
    // Recursion : subset SUm
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sumNums = accumulate(nums.begin(), nums.end(), 0);
        target = (sumNums + target) / 2;
        return solve(nums, target, n - 1);
    }
    int solve(vector<int> nums, int target, int i)
    {
        if (i == 0)
            return nums[i] == target;
        if (target == 0)
            return 1;

        // Pick : Dont pick if nums[i] > target
        int p = 0;
        if (nums[i] <= target)
            p = solve(nums, target - nums[i], i - 1);
        // noPick
        int np = solve(nums, target, i - 1);

        return  p + np;
    }
};

class Solution1
{
    // Recursion : Optimised
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return solve(nums, target, n - 1);
    }
    int solve(vector<int> &nums, int target, int n)
    {
        // Base Condition
        if (n == -1)
        {
            if (target == 0)
            {
                return 1;
            }
            return 0;
        }

        // Assign positive
        int pos = solve(nums, target - nums[n], n - 1);
        // Assign negative
        int neg = solve(nums, target + nums[n], n - 1);

        return pos + neg;
    }
};

class Solution
{
    // BruteForce : Recursion
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size(), count = 0;
        solve(nums, count, target, n - 1);
        return count;
    }
    void solve(vector<int> &nums, int &count, int target, int n)
    {
        // Base Condition
        if (n == -1)
        {
            if (target == 0)
            {
                ++count;
            }
            return;
        }

        // Assign positive
        solve(nums, count, target - nums[n], n - 1);
        // Assign negative
        solve(nums, count, target + nums[n], n - 1);
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution2 Obj1;
    cout << Obj1.findTargetSumWays(nums, target);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}