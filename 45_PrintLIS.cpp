// Print Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std ;

class Solution2 {
    // Print 
public:
    vector<int> LongestIncreasingSubSequence(vector<int> nums) {
        int n = nums.size();
        // dp[i] signifies the size of subsequece if ss ends at index i
        vector<int> dp(n, 1), hash(n);
        for (int i = 0; i < n; ++i){hash[i] = i ;}
        int maxIndex = 0, maxVal = INT_MIN;
        for (int i = 0; i < n; ++i)
        {    
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i] && dp[i] < dp[j]+1) {
                    hash[i] = j ;
                    dp[i] = dp[j]+1;
                    if (maxVal < dp[i]) {
                        maxVal = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
        vector<int> LIS;
        while(true) {
            LIS.emplace_back(nums[maxIndex]);
            if (maxIndex == hash[maxIndex]) break;
            maxIndex = hash[maxIndex];
        };
        
        reverse(LIS.begin(), LIS.end()); 
        return LIS;
    }
};

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
    
    Solution2 Obj;
    vector<int> nums = {5, 6, 8, 3, 26, 90};

    vector<int> res = Obj.LongestIncreasingSubSequence(nums);
    for(auto &it: res) {
        cout << it << " ";
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}