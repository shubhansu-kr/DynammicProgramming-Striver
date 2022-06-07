// Maximum Sum of Non Adjacent element -
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

// You are given an array/list of ‘N’ integers. You are supposed to return the
// maximum sum of the subsequence with the constraint that no two elements are
// adjacent in the given array/list.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Using recursion to find all the valid sub-Sequence
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int sum = 0, ans = -1;
        subSum(nums, sum, ans);
        return ans;
    }
    void subSum(vector<int> &nums, int &sum, int &ans, int i = 0)
    {
        if (i >= nums.size())
        {
            ans = max(ans, sum);
            return;
        }
        sum += nums[i];
        subSum(nums, sum, ans, i + 2);
        sum -= nums[i];
        subSum(nums, sum, ans, i + 1);
    }
};

class Solution
{
    // Tabulation
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size());
        dp[0] = nums[0], dp[1] = nums[1];
        for (int i = 2; i < nums.size(); ++i)
        {
            int subMax = -1;
            for (int j = 0; j < i - 1; ++j)
            {
                int s = dp[j] + nums[i];
                subMax = max(s, subMax);
            }
            dp[i] = subMax;
        }
        return dp[nums.size() - 1];
    }
};

int main()
{
    Solution1 obj1;
    vector<int> nums = {9, 9, 5, 7, 2, 0, 3};
    cout << obj1.maximumNonAdjacentSum(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}