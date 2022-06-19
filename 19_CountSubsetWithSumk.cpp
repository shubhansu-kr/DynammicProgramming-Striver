// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the
// sum of the minimum and maximum element on it is less or equal to target.
// Since the answer may be too large, return it modulo 109 + 7.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursion optimised
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        return solve(nums, target, n - 1);
    }
    int solve(vector<int> nums, int target, int i)
    {
        if (i == 0)
            return nums[i] == target;
        if (target == 0) return 1 ;

        // Pick : Dont pick if nums[i] > target
        int p = 0;
        if (nums[i] <= target)    
            p = solve(nums, target - nums[i], i - 1);
        // noPick
        int np = solve(nums, target, i - 1);

        return p + np;
    }
};

class Solution
{
    // BruteForce Solution : Recursion
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size(), count = 0;
        solve(nums, count, target, n - 1);

        return count;
    }
    void solve(vector<int> nums, int &count, int target, int i)
    {
        if (i < 0)
        {
            if (target == 0)
            {
                ++count;
            }
            return;
        }
        // pick
        solve(nums, count, target - nums[i], i - 1);
        // not pick
        solve(nums, count, target, i - 1);
    }
};

int main()
{
    // 1,2,3 | 1,5 | 2,4 | 6 ---> 4 ;
    vector<int> nums = {1, 4, 3, 2, 5, 6};
    int target = 6;

    Solution1 Obj1;
    cout << Obj1.numSubseq(nums, target);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}