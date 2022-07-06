// https://leetcode.com/problems/coin-change/

// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the
// coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Tabulation: Space Optimised  
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        vector<int> cp(amount+1, 0), temp(amount+1, 0);

        for (int i = 1; i <= amount; ++i)
        {
            if (i % coins[0] == 0) cp[i] = i / coins[0];
            else cp[i] = 1e9;
        }
 
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                // Pick
                int pick = INT_MAX;
                if (amount >= coins[i]) pick = 1 + temp[j - coins[i]];
                // No Pick
                int noPick = cp[j];
                temp[j] = min(pick, noPick);
            }
            cp = temp;
        }

        int ans = cp[amount];
        return ans >= 1e9 ? -1 : ans;
    }
};

class Solution3
{
    // Tabulation 
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 1; i <= amount; ++i)
        {
            if (i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }
 
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                // Pick
                int pick = INT_MAX;
                if (amount >= coins[i]) pick = 1 + dp[i][j - coins[i]];
                // No Pick
                int noPick = dp[i - 1][j];
                dp[i][j] = min(pick, noPick);
            }
        }

        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};

class Solution2
{
    // Recursion: Memoization
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins, dp, amount, n - 1);
        return ans >= 1e9 ? -1 : ans;
    }
    int solve(vector<int> &coins, vector<vector<int>> &dp, int amount, int n)
    {
        // base condition
        if (amount == 0)
            return 0;
        if (n == -1)
            return 1e9;

        if (dp[n][amount] != -1)
            return dp[n][amount];
        // Pick
        int pick = INT_MAX;
        if (amount >= coins[n])
            pick = 1 + solve(coins, dp, amount - coins[n], n);
        // No Pick
        int noPick = solve(coins, dp, amount, n - 1);

        return dp[n][amount] = min(pick, noPick);
    }
};

class Solution1
{
    // Recursion: Optimised
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = solve(coins, amount, n - 1);
        return ans >= 1e9 ? -1 : ans;
    }
    int solve(vector<int> &coins, int amount, int n)
    {
        // base condition
        if (amount == 0)
            return 0;
        if (n == -1)
            return 1e9;

        // Pick
        int pick = INT_MAX;
        if (amount >= coins[n])
            pick = 1 + solve(coins, amount - coins[n], n);
        // No Pick
        int noPick = solve(coins, amount, n - 1);

        return min(pick, noPick);
    }
};

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
    vector<int> coins = {1,2,5};
    int amount = 11;

    Solution4 Obj1;
    cout << Obj1.coinChange(coins, amount);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}