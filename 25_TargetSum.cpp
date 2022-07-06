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
        if (n == -1) {
            if (target == 0) {
                ++count ;
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

    Solution Obj1;
    cout << Obj1.findTargetSumWays(nums, target);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}