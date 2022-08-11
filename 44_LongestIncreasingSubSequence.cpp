// https://leetcode.com/problems/longest-increasing-subsequence/

// Given an integer array nums, return the length of the longest
// strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by
// deleting some or no elements without changing the order of the
// remaining elements. For example, [3,6,2,7] is a subsequence of
// the array [0,3,1,6,2,2,7].

#include <bits/stdc++.h>
using namespace std;

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