// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// You are given an array prices where prices[i] is the price of a 
// given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy 
// one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. 
// If you cannot achieve any profit, return 0.

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // Min. 
public:
    int maxProfit(vector<int>& prices) {
        vector<int> track(prices.size());
        int mini = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            track[i] = mini;
            mini = min(mini, prices[i]);
        }
        int ans = 0;
        for (int i = prices.size()-1; i > 0; --i)
        {
            track[i] = prices[i] - track[i];
            ans = max(ans, track[i]);
        }
        return ans;
    }
};

class Solution {
    // BruteForce : TLE 
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size()-1; ++i)
        {
            for (int j = i+1; j < prices.size(); ++j)
            {
                profit = max(profit, (prices[j]-prices[i]));
            }
        }
        return profit;
    }
};

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}