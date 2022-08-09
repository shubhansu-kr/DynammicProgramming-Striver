// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

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