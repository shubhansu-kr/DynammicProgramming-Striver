// Print Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // Classic DP 
public:
    int LongestIncreasingSubSequence(vector<int> nums) {
        int n = nums.size();
        // dp[i] signifies the size of subsequece if ss ends at index i
        vector<int> dp(n, 1);         
        for (int i = 0; i < n; ++i)
        {    
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int LongestIncreasingSubSequence(vector<int> nums) {
        int n = nums.size();
        vector<int> curr(n+1, 0), next(n+1, 0);
        for (int i = n-1; i >= 0; --i)
        {
            for (int j = i-1; j >= -1 ; --j)
            {
                int len = 0 + next[j+1];
                if (j == -1 || nums[i] > nums[j]) {
                    len = max(len, 1 + next[i+1]);
                }
                curr[j+1] = len;
            }
            next = curr;
        }
        return  next[0];        
    }
};

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}