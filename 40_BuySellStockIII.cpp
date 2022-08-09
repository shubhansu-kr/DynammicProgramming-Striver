// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

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