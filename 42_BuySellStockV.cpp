// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// You are given an array prices where prices[i] is the price of a given
// stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions
// as you like (i.e., buy one and sell one share of the stock multiple times) with
// the following restrictions:
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must
// sell the stock before you buy again).

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursion: Memoization  
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(2, -1)));
        return trader(prices, dp, true);
    }

    int trader(vector<int> &prices, vector<vector<vector<int>>> &dp, int buy, int cooldown = 0, int i = 0)
    {
        // base Condition
        if (i == prices.size()) return 0;
        if (dp[i][buy][cooldown] != -1) return dp[i][buy][cooldown];

        int take = INT_MIN, noTake = INT_MIN;
        if (buy)
        {
            if (!cooldown)
            {
                take = trader(prices, dp, false, cooldown, i + 1) - prices[i];
            }
            noTake = trader(prices, dp, buy, false, i + 1); 
        }
        else
        {
            take = trader(prices, dp, true, true, i + 1) + prices[i];
            noTake = trader(prices, dp, buy, cooldown, i + 1);
        }

        return dp[i][buy][cooldown] = max(take, noTake);
    }
};

class Solution
{
    // BruteForce: Recursion 
public:
    int maxProfit(vector<int> &prices)
    {
        return trader(prices, true);
    }
    int trader(vector<int> &prices, int buy, int cooldown = 0, int i = 0)
    {
        // base Condition
        if (i == prices.size()) return 0;

        int take = INT_MIN, noTake = INT_MIN;
        if (buy)
        {
            if (!cooldown)
            {
                take = trader(prices, false, cooldown, i + 1) - prices[i];
            }
            noTake = trader(prices, buy, false, i + 1); 
        }
        else
        {
            take = trader(prices, true, true, i + 1) + prices[i];
            noTake = trader(prices, buy, cooldown, i + 1);
        }

        return max(take, noTake);
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}