// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// You are given an integer array prices where prices[i] is the price of a
// given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only
// hold at most one share of the stock at any time. However, you can buy it
// then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Recursion: Memoization
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return solve(prices, dp);
    }
    int solve (vector<int> &prices, vector<vector<int>> &dp, int stock = 0, int i = 0) {
        // base case 
        if (i == prices.size()) return 0 ;

        if (dp[i][stock] != -1) return dp[i][stock];
        int noAction = solve (prices, dp, stock, i+1);
        int action = solve(prices, dp, !stock, i+1);
        stock ? action += prices[i] : action -= prices[i];

        return dp[i][stock] = max(action, noAction); 
    } 
};

class Solution1
{
    // BruteForce: Recursion 
public:
    int maxProfit(vector<int> &prices)
    {
        return solve(prices);
    }
    int solve (vector<int> &prices, bool stock = false, int i = 0) {
        // base case 
        if (i == prices.size()) return 0 ;

        int noAction = solve (prices, stock, i+1);
        int action = solve(prices, !stock, i+1);
        stock ? action += prices[i] : action -= prices[i];

        return max(action, noAction); 
    } 
};

class Solution
{
    // Intution
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, stock = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            if (!stock && prices[i + 1] > prices[i])
            {
                profit -= prices[i];
                stock = 1;
            }
            else if (stock) {
                if (prices[i+1] > prices[i]){
                    continue;
                }
                else {
                    profit += prices[i];
                    stock = 0 ;
                }
            }
        }
        if (stock) {
            profit += prices.back();
        }
        return profit ;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}