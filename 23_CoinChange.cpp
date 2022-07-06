// https://leetcode.com/problems/coin-change/

// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the
// coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce: Recursion
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size(), ans = INT_MAX, count = 0;
        solve(coins, ans, count, amount, n - 1);
        return ans == INT_MAX ? -1 : ans;
    }
    void solve(vector<int> &coins, int &ans, int &count, int &amount, int n)
    {
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (n == -1)
        {
            return;
        }
        if (amount >= coins[n])
        {
            amount -= coins[n];
            ++count;
            solve(coins, ans, count, amount, n);
            --count;
            amount += coins[n];
        }
        solve(coins, ans, count, amount, n - 1);
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution Obj1;
    cout << Obj1.coinChange(coins, amount);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}