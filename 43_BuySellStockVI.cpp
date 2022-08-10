// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// You are given an array prices where prices[i] is the price of a given stock on
// the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many
// transactions as you like, but you need to pay the transaction fee
// for each transaction.
// Note: You may not engage in multiple transactions simultaneously (i.e.,
// you must sell the stock before you buy again).

#include <bits/stdc++.h>
using namespace std;

class Solution4 {
    // Discussion solution
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT_MIN; 
        for(int p:prices) {
            int tmp = s0;
            s0 = max(s0, s1+p);
            s1 = max(s1, tmp-p-fee);
        }
        return s0;
    }
};

class Solution3
{
    // Tabulation: Space Optimised 
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> temp(2, 0), curr(2, 0);
        for (int i = n-1; i >= 0; --i)
        {
            for (int stock = 0; stock < 2; ++stock)
            {
                int action = curr[!stock], noAction = curr[stock];
                stock ? action += (prices[i] - fee): action -= prices[i];
                temp[stock] = max(action, noAction);
            }
            curr = temp;
        }        
        return curr[0];
    }
};

class Solution2
{
    // Tabulation 
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        for (int i = n-1; i >= 0; --i)
        {
            for (int stock = 0; stock < 2; ++stock)
            {
                int action = dp[i+1][!stock], noAction = dp[i+1][stock];
                stock ? action += (prices[i] - fee): action -= prices[i];
                dp[i][stock] = max(action, noAction);
            }
        }        
        return dp[0][0];
    }
};

class Solution1
{
    // Recursion: Memoization 
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return trader(prices, dp, fee);
    }
    int trader(vector<int> &prices, vector<vector<int>> &dp, int fee, int i = 0, int stock = 0) {
        if (i == prices.size()) return 0; 
        if (dp[i][stock] != -1) return dp[i][stock];
        int action = trader(prices, dp, fee, i+1, !stock), noAction = trader(prices, dp, fee, i+1, stock);
        stock ? action += (prices[i] - fee): action -= prices[i];
        return dp[i][stock] = max(action, noAction);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return trader(prices, fee);
    }
    int trader(vector<int> &prices, int fee, int i = 0, int stock = 0) {
        if (i == prices.size()) return 0; 
        int action = trader(prices, fee, i+1, !stock), noAction = trader(prices, fee, i+1, stock);
        stock ? action += (prices[i] - fee): action -= prices[i];
        return max(action, noAction);
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}