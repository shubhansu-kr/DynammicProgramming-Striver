// https://leetcode.com/problems/coin-change-2/

// You are given an integer array coins representing coins of different denominations
// and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money
// cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Tabulation : Space Optimised 
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1));
        vector<int> cp(amount+1, 1), temp(amount+1, 1);

        for (int amt = 1; amt <= amount; ++amt)
        {
            if (amt % coins[0] == 0) cp[amt] = 1;
            else cp[amt] = 0;
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                int pick = 0;
                if (j >= coins[i]) pick = temp[j - coins[i]];
                int noPick = cp[j];
                temp[j] = pick + noPick;
            }
            cp = temp ;
        }
        return cp[amount];
    }
};

class Solution3
{
    // Tabulation
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1));

        for (int amt = 1; amt <= amount; ++amt)
        {
            if (amt % coins[0] == 0) dp[0][amt] = 1;
            else dp[0][amt] = 0;
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                int pick = 0;
                if (j >= coins[i]) pick = dp[i][j - coins[i]];
                int noPick = dp[i - 1][j];
                dp[i][j] = pick + noPick;
            }
        }
        return dp[n - 1][amount];
    }
};

class Solution2
{
    // Recursion: <Memoization
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(coins, dp, amount, n - 1);
    }
    int solve(vector<int> &coins, vector<vector<int>> &dp, int amount, int n)
    {
        // base condition
        if (amount == 0)
            return 1;
        if (n == -1)
            return 0;

        if (dp[n][amount] != -1)
            return dp[n][amount];

        // pick
        int pick = 0;
        if (amount >= coins[n])
            pick = solve(coins, dp, amount - coins[n], n);
        // noPick
        int noPick = solve(coins, dp, amount, n - 1);

        return dp[n][amount] = pick + noPick;
    }
};

class Solution1
{
    // Recursion: Optimised
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return solve(coins, amount, n - 1);
    }
    int solve(vector<int> &coins, int amount, int n)
    {
        // base condition
        if (amount == 0)
            return 1;
        if (n == -1)
            return 0;

        // pick
        int pick = 0;
        if (amount >= coins[n])
            pick = solve(coins, amount - coins[n], n);
        // noPick
        int noPick = solve(coins, amount, n - 1);

        return pick + noPick;
    }
};

class Solution
{
    // BruteForce : Recursion
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

    Solution1 Obj1;
    cout << Obj1.change(amount, coins);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}