// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

// You are given an integer array nums of 2 * n integers. You need
// to partition nums into two arrays of length n to minimize the
// absolute difference of the sums of the arrays. To partition nums,
// put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Using subset sum
public:
    int minimumDifference(vector<int> &nums)
    {
        int totalSum = 0;
        for (int &num : nums)
            totalSum += num;

        int k = totalSum, n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(k + 1));
        // Base case : For all target 0: True, For ind 0 -> nums[0] == true;
        for (int i = 0; i < n; ++i)
            dp[i][0] = true;
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                bool noTake = dp[i - 1][j];
                bool take = false;
                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];
                dp[i][j] = take || noTake;
            }
        }

        int mini = 1e9;
        for (int i = 0; i < totalSum / 2; ++i)
        {
            if (dp[n - 1][i] == true)
            {
                mini = min(mini, abs(totalSum - 2 * i));
            }
        }

        return mini;
    }
};

class Solution
{
    // BruteForce : Recursion : Try out all possible subsets : TLE
    // Note : Both the subset should be non-empty : Wrong Solution
public:
    int minimumDifference(vector<int> &nums)
    {
        int right = 0, left = 0, n = nums.size(), ans = INT_MAX;
        for (int x : nums)
            right += x;
        int sum = right;
        solve(nums, left, right, ans, sum, n - 1);
        return ans;
    }

    void solve(vector<int> &nums, int left, int right, int &ans, int &sum, int i)
    {
        if (i < 0)
        {
            if (left == 0 && right == sum)
                return;
            ans = min(ans, abs(left - right));
            return;
        }

        // Pick
        solve(nums, left + nums[i], right - nums[i], ans, sum, i - 1);
        // Not Pick
        solve(nums, left, right, ans, sum, i - 1);
    }
};

int main()
{
    vector<int> nums = {4, 36};

    Solution1 Obj1;
    cout << Obj1.minimumDifference(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}