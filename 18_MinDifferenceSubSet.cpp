// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

// You are given an integer array nums of 2 * n integers. You need
// to partition nums into two arrays of length n to minimize the
// absolute difference of the sums of the arrays. To partition nums,
// put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce : Recursion : Try out all possible subsets
    // Note : Both the subset should be non-empty
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
    vector<int> nums = {-36, 36};

    Solution Obj1;
    cout << Obj1.minimumDifference(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}