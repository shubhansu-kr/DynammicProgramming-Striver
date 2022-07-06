// https://leetcode.com/problems/coin-change-2/

// You are given an integer array coins representing coins of different denominations
// and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money
// cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size(), count = 0;
        solve(coins, count, amount, n - 1);
        return count;
    }
    void solve(vector<int> &coins, int &count, int &amount, int n)
    {
        if (amount == 0)
        {
            ++count;
            return;
        }
        if (n == -1)
        {
            return;
        }
        if (amount >= coins[n])
        {
            amount -= coins[n];
            solve(coins, count, amount, n);
            amount += coins[n];
        }
        solve(coins, count, amount, n - 1);
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    Solution Obj1;
    cout << Obj1.coinChange(coins, amount);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}