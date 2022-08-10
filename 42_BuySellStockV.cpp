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

class Solution8 {
    // Tabulation: SpaceOptimised 
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        vector<int> A(2, 0), B(2, 0), C(2, 0);
        for (int i = n-1; i >= 0; --i)
        {
            for (int stock = 0; stock < 2; ++stock)
            {
                int action = 0, noAction = B[stock];
                if (stock) action = C[0] + prices[i];
                else action = B[1] - prices[i];
                A[stock] = max(action, noAction);
            }
            C = B, B = A;
        }
        
        return A[0];
    }
};

class Solution7 {
    // Tabulation 
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for (int i = n-1; i >= 0; --i)
        {
            for (int stock = 0; stock < 2; ++stock)
            {
                int action = 0, noAction = dp[i+1][stock];
                if (stock) action = dp[i+2][0] + prices[i];
                else action = dp[i+1][1] - prices[i];
                dp[i][stock] = max(action, noAction);
            }
        }
        
        return dp[0][0];
    }
};

class Solution6 {
    // Recursion: Memoization 
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return trader(prices, dp);
    }

    int trader (vector<int> &prices, vector<vector<int>> &dp, int i = 0, int stock = 0) {
        if (i >= prices.size()) return 0;
        if (dp[i][stock] != -1) return dp[i][stock];
        int action = 0, noAction = 0;
        if (stock) {
            action = trader(prices, dp, i+2) + prices[i];
            noAction = trader(prices, dp, i+1, 1);
        }
        else {
            action = trader(prices, dp, i+1, 1) - prices[i];
            noAction = trader(prices, dp, i+1);
        }

        return dp[i][stock] = max(action, noAction);
    }
};

class Solution5 {
    // BruteForce: Recursion 
public:
    int maxProfit(vector<int> &prices) {
        return trader(prices);
    }

    int trader (vector<int> &prices, int i = 0, int stock = 0) {
        if (i >= prices.size()) return 0;
        
        int action = 0, noAction = 0;
        if (stock) {
            action = trader(prices, i+2) + prices[i];
            noAction = trader(prices, i+1, 1);
        }
        else {
            action = trader(prices, i+1, 1) - prices[i];
            noAction = trader(prices, i+1);
        }

        return max(action, noAction);
    }
};

class Solution4
{
    // Discussion solution 
public:
    int maxProfit(vector<int> &prices)
    {
        int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);
            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        return sell;
    }
};

class Solution3
{
    // Tabulation: Space Optimised 
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(2, 0)), temp(2, vector<int>(2, 0));
                
        for (int i = n-1; i >= 0; --i)
        {
            for (int buy = 0;  buy < 2; ++buy)
            {
                for (int cooldown = 0; cooldown < 2; ++cooldown)
                {
                    int take = INT_MIN, noTake = INT_MIN;
                    if (buy)
                    {
                        if (!cooldown) take = curr[false][cooldown] - prices[i];
                        noTake = curr[buy][false]; 
                    }
                    else
                    {
                        take = curr[true][true] + prices[i];
                        noTake = curr[buy][cooldown];
                    }
                    temp[buy][cooldown] = max(take, noTake);
                }   
            }
            curr = temp;
        }
        return curr[1][0];
    }
};

class Solution2
{
    // Tabulation 
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int>(2, 0)));
        
        for (int i = n-1; i >= 0; --i)
        {
            for (int buy = 0;  buy < 2; ++buy)
            {
                for (int cooldown = 0; cooldown < 2; ++cooldown)
                {
                    int take = INT_MIN, noTake = INT_MIN;
                    if (buy)
                    {
                        if (!cooldown) take = dp[i + 1][false][cooldown] - prices[i];
                        noTake = dp[i + 1][buy][false]; 
                    }
                    else
                    {
                        take = dp[i + 1][true][true] + prices[i];
                        noTake = dp[i + 1][buy][cooldown];
                    }
                    dp[i][buy][cooldown] = max(take, noTake);
                }   
            }
        }
        return dp[0][1][0];
    }
};

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