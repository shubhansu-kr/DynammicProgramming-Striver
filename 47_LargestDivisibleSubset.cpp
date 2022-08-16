// https://leetcode.com/problems/largest-divisible-subset/

// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce: Recursion
    // In Subset Order does not matter
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // dp[i] signifies the size of subsequece if ss ends at index i
        vector<int> dp(n, 1), hash(n);
        for (int i = 0; i < n; ++i){hash[i] = i ;}
        int maxIndex = 0, maxVal = INT_MIN;
        for (int i = 0; i < n; ++i)
        {    
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j]+1) {
                    hash[i] = j ;
                    dp[i] = dp[j]+1;
                    if (maxVal < dp[i]) {
                        maxVal = dp[i];
                        maxIndex = i;
                    }
                } 
            }
        }
        vector<int> LDS;
        while(true) {
            LDS.emplace_back(nums[maxIndex]);
            if (maxIndex == hash[maxIndex]) break;
            maxIndex = hash[maxIndex];
        };
        
        reverse(LDS.begin(), LDS.end()); 
        return LDS;
    }
};

int main()
{
    Solution Obj1;
    vector<int> nums = {1, 2, 4, 6};

    vector<int> ans = Obj1.largestDivisibleSubset(nums);
    for (auto &a : ans)
        cout << a << " ";
    cout << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}