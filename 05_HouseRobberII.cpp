// https://leetcode.com/problems/house-robber-ii/

// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed. All houses at this
// place are arranged in a circle. That means the first house is the
// neighbor of the last one. Meanwhile, adjacent houses have a security
// system connected, and it will automatically contact the police if two
// adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each
// house, return the maximum amount of money you can rob tonight without
// alerting the police.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Solution 2 improved
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int l = solve(nums,  n, 1);
        --n;
        int r = solve(nums,  n);
        return max(l, r) ;
    }
    int solve(vector<int> &nums,  int &n, int i = 0)
    {
        if (i >= n)
        {
            return 0;
        }
        // l -> Not picked
        // r -> picked

        int l = solve(nums, n, i+1);
        int r = solve(nums, n, i+2) + nums[i];

        return max(l, r);
    }
};

class Solution2
{
    // Recursion Solution for adjacent sum - Using i as a parameter
    // And evaluating first and last elements seprately.
public:
    int rob(vector<int> &nums)
    {
        int ans1 = INT_MIN, ans2 = INT_MIN, sum = 0, n = nums.size();
        solve(nums, sum, ans1, n, 1);
        --n;
        solve(nums, sum, ans2, n);
        return max(ans1, ans2);
    }
    void solve(vector<int> &nums, int &sum, int &ans, int &n, int i = 0)
    {
        if (i >= n)
        {
            ans = max(ans, sum);
            return;
        }
        // l -> Not picked
        // r -> picked

        sum += nums[i];
        solve(nums, sum, ans, n, i + 2);
        sum -= nums[i];
        solve(nums, sum, ans, n, i + 1);
    }
};

class Solution1
{
    // Recursion Solution for adjacent sum - Using i as a parameter
public:
    int rob(vector<int> &nums)
    {
        int ans = INT_MIN, sum = 0, n = nums.size();
        solve(nums, sum, ans, n);
        return ans;
    }
    void solve(vector<int> &nums, int &sum, int &ans, int &n, int i = 0)
    {
        if (i >= n)
        {
            ans = max(ans, sum);
            return;
        }
        // l -> Not picked
        // r -> picked

        sum += nums[i];
        solve(nums, sum, ans, n, i + 2);
        sum -= nums[i];
        solve(nums, sum, ans, n, i + 1);
    }
};
class Solution
{
    // Recursion Solution for adjacent sum
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
    vector<int> nums = {2, 3, 3};

    Solution3 Obj1;
    cout << Obj1.rob(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}