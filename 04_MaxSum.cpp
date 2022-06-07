// Maximum Sum of Non Adjacent element -
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

// You are given an array/list of ‘N’ integers. You are supposed to return the
// maximum sum of the subsequence with the constraint that no two elements are
// adjacent in the given array/list.

#include <bits/stdc++.h>
using namespace std;

class Solution6
{
    // Tabulation: Space optimisation
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int prev = nums[0], prev1 = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            // Take
            int l = nums[i] + prev1;
            // No take
            int r = prev;

            prev1 = prev;
            prev = max(l, r);
        }
        return prev;
    }
};

class Solution5
{
    // Tabulation
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            // Take
            int l = nums[i] + ((i > 1) ? dp[i - 2] : 0);
            // No take
            int r = dp[i - 1];

            dp[i] = max(l, r);
        }
        return dp.back();
    }
};

class Solution4
{
    // Memoization
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return subSum(nums, dp, n - 1);
    }
    int subSum(vector<int> &nums, vector<int> &dp, int n)
    {
        if (n < 1)
        {
            return n == 0 ? nums[0] : 0;
        }
        if (dp[n] != -1)
            return dp[n];

        int l = nums[n] + subSum(nums, dp, n - 2);
        int r = subSum(nums, dp, n - 1);
        return dp[n] = max(l, r);
    }
};

class Solution3
{
    // Memoization
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int sum = 0, n = nums.size() - 1;
        vector<int> dp(n + 1, -1);
        return subSum(nums, sum, n, dp);
    }
    int subSum(vector<int> &nums, int &sum, int n, vector<int> &dp)
    {
        if (n <= 0)
        {
            return sum;
        }
        if (dp[n] != -1)
            return dp[n];
        sum += nums[n];
        int l = subSum(nums, sum, n - 2, dp);
        sum -= nums[n];
        int r = subSum(nums, sum, n - 1, dp);
        return dp[n] = max(l, r);
    }
};

class Solution2
{
    // Using recursion to find all the valid sub-Sequence
public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int sum = 0, ans = -1, n = nums.size();
        subSum(nums, sum, ans, n);
        return ans;
    }
    void subSum(vector<int> &nums, int &sum, int &ans, int n)
    {
        if (n <= 0)
        {
            ans = max(ans, sum);
            return;
        }
        sum += nums[n];
        subSum(nums, sum, ans, n - 2);
        sum -= nums[n];
        subSum(nums, sum, ans, n - 1);
    }
};

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
    Solution6 obj1;
    vector<int> nums = {9, 9, 5, 7, 2, 0, 3};
    cout << obj1.maximumNonAdjacentSum(nums);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}