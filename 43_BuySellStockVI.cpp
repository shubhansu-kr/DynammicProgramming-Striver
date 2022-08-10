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