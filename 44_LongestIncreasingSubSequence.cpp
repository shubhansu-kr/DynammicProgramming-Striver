// https://leetcode.com/problems/longest-increasing-subsequence/

// Given an integer array nums, return the length of the longest
// strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by
// deleting some or no elements without changing the order of the
// remaining elements. For example, [3,6,2,7] is a subsequence of
// the array [0,3,1,6,2,2,7].

#include <bits/stdc++.h>
using namespace std;

// Discussion Solution
// https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C++Python-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

/* 
class Solution8 { // 256 ms, faster than 42.84%
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution7 { // 8 ms, faster than 91.61%
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};

class Solution6 {
public:
    vector<int> pathOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub, subIndex; // Store index instead of value for tracing path purpose
        vector<int> path(n, -1); // path[i] point to the index of previous number in LIS
        for (int i = 0; i < n; ++i) {
            if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
                path[i] = sub.empty() ? -1 : subIndex[sub.size() - 1];
                sub.push_back(nums[i]);
                subIndex.push_back(i);
            } else {
                int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                path[i] = idx == 0 ? -1 : subIndex[idx - 1];
                sub[idx] = nums[i];
                subIndex[idx] = i;
            }
        }
        vector<int> ans;
        int t = subIndex[subIndex.size() - 1];
        while (t != -1) {
            ans.push_back(nums[t]);
            t = path[t];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class MaxBIT { // One-based indexing
    vector<int> bit;
public:
    MaxBIT(int size) {
        bit.resize(size + 1);
    }
    int get(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx)
            ans = max(ans, bit[idx]);
        return ans;
    }
    void update(int idx, int val) {
        for (; idx < bit.size(); idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
};
class Solution5 { // 16 ms, faster than 72.16%
public:
    int lengthOfLIS(vector<int>& nums) {
        int BASE = 10001;
        MaxBIT bit(20001);
        for (int x : nums) {
            int subLongest = bit.get(BASE + x - 1);
            bit.update(BASE + x, subLongest + 1);
        }
        return bit.get(20001);
    }
};

*/

// My Solution: 
class Solution4
{
    // Tabulation: SpaceOptimisation 
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> curr(n+1, 0), temp(n+1, 0);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                int pick = -1e9;
                if (j == 0 || nums[j-1] > nums[i-1]) {pick = 1 + curr[i];}
                int noPick = curr[j];
                temp[j] = max(pick, noPick);
            }
            curr = temp;
        }
        return curr[0];
    }
};

class Solution3
{
    // Tabulation 
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                int pick = -1e9;
                if (j == 0 || nums[j-1] > nums[i-1]) {pick = 1 + dp[i-1][i];}
                int noPick = dp[i-1][j];
                dp[i][j] = max(pick, noPick);
            }
        }
        return dp[n][0];
    }
};

class Solution2
{
    // Wrong Solution : Runtime error 
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                int pick = -1e9;
                if (j == 0 || nums[j] > nums[i-1]) {pick = 1 + dp[i-1][i];}
                int noPick = dp[i-1][j];
                dp[i][j+1] = max(pick, noPick);
            }
        }
        return dp[n][0];
    }
};

class Solution2
{
    // Recursion: Memoization  
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, dp, n-1);
    }
    int solve(vector<int> &nums, vector<vector<int>> &dp, int i, int j = -1)
    {
        if (i == -1) return 0;
        if (dp[i][j+1] != -1) return dp[i][j+1];
        int pick = -1e9;
        if (j == -1 || nums[j] > nums[i]) {pick = 1 + solve(nums, dp, i-1, i);}
        int noPick = solve(nums, dp, i-1, j);
        return dp[i][j+1] = max(pick, noPick);
    }
};

class Solution1
{
    // BruteForce: Recursion 
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n-1);
    }
    int solve(vector<int> &nums, int i, int j = -1)
    {
        if (i == -1) return 0;
        int pick = -1e9;
        if (j == -1 || nums[j] > nums[i]) {pick = 1 + solve(nums, i-1, i);}
        int noPick = solve(nums, i-1, j);
        return max(pick, noPick);
    }
};

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