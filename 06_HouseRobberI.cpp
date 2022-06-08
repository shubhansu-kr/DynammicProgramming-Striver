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
    Solution Obj1;
    cout << Obj1.rob(nums);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}