// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// You are given an integer array prices where prices[i] is the price of a 
// given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most 
// k transactions.
// Note: You may not engage in multiple transactions simultaneously 
// (i.e., you must sell the stock before you buy again).

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0)), temp(2, vector<int>(k+1, 0));
        for (int i = n-1; i >= 0; --i)
        {
            for (int buy = 0; buy < 2; ++buy)
            {
                for (int cap = 1; cap <= k; ++cap)
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
        
        return curr[1][k];
    }
};

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}