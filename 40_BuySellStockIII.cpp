// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation: Space Optimised 
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0)), temp(2, vector<int>(3, 0));
        for (int i = n-1; i >= 0; --i)
        {
            for (int buy = 0; buy < 2; ++buy)
            {
                for (int cap = 1; cap < 3; ++cap)
                {
                    int take, noTake;
                    if (buy) {
                        take = curr[0][cap] - prices[i];
                        noTake = curr[1][cap];
                    }
                    else {
                        take = curr[1][cap-1] + prices[i];
                        noTake =curr[0][cap];
                    }
                    temp[buy][cap] = max(take, noTake);
                }                
            }
            curr = temp;
        }
        
        return curr[1][2];
    }
};

class Solution2
{
    // Tabulation 
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n-1; i >= 0; --i)
        {
            for (int buy = 0; buy < 2; ++buy)
            {
                for (int cap = 1; cap < 3; ++cap)
                {
                    int take, noTake;
                    if (buy) {
                        take = dp[i+1][0][cap] - prices[i];
                        noTake = dp[i+1][1][cap];
                    }
                    else {
                        take = dp[i+1][1][cap-1] + prices[i];
                        noTake = dp[i+1][0][cap];
                    }
                    dp[i][buy][cap] = max(take, noTake);
                }                
            }
        }
        
        return dp[0][1][2];
    }
};

class Solution1
{
    // Recursion: Memoization  
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return trade (prices, dp, 0, true) ;
    }

    int trade(vector<int> &prices, vector<vector<vector<int>>> &dp, int i, int buy, int cap = 2) {
        // Base conditions 
        if (i == prices.size()) return 0;
        if (!cap) return 0;

        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int take, noTake;
        if (buy) {
            take = trade(prices, dp, i+1, false, cap) - prices[i];
            noTake = trade(prices, dp, i+1, true, cap);
        }
        else {
            take = trade(prices, dp, i+1, true, cap-1) + prices[i];
            noTake = trade(prices, dp, i+1, false, cap);
        }

        return dp[i][buy][cap] = max(take, noTake);
    }
};

class Solution
{
    // BruteForce: Recursion 
public:
    int maxProfit(vector<int> &prices)
    {
        return trade (prices, 0, true) ;
    }

    int trade(vector<int> &prices, int i, int buy, int cap = 2) {
        // Base conditions 
        if (i == prices.size()) return 0;
        if (!cap) return 0;

        int take, noTake;
        if (buy) {
            take = trade(prices, i+1, false, cap) - prices[i];
            noTake = trade(prices, i+1, true, cap);
        }
        else {
            take = trade(prices, i+1, true, cap-1) + prices[i];
            noTake = trade(prices, i+1, false, cap);
        }

        return max(take, noTake) ;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}