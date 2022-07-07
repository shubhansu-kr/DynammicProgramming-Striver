// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each
// size has a cost associated with it. Determine the maximum cost obtained by cutting
// the rod and selling its pieces.

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Recursion: Memoization 
public:
    int solve(vector<int> &price,vector<vector<int>> &dp, int len, int n)
    {
        if (n == -1) return 0;
        
        if (dp[n][len] != -1) return dp[n][len];
        
        int cut = 0;
        if (len >= n+1) cut = price[n] + solve(price,dp, len-(n+1), n);    
        int noCut = solve(price,dp, len, n - 1);
        return dp[n][len] = max(cut, noCut);
    }

    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(price,dp, n, n-1);
    }
};

class Solution1
{
    // Recursion: Optimised
public:
    int solve(vector<int> &price, int len, int n)
    {
        if (n == -1) return 0;
        int cut = 0;
        if (len >= n+1) cut = price[n] + solve(price, len-(n+1), n);    
        int noCut = solve(price, len, n - 1);
        return max(cut, noCut);
    }

    int cutRod(vector<int> &price, int n)
    {
        return solve(price, n, n-1);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    void solve(vector<int> &price, int &ans, int &cost, int &len, int n)
    {
        // base condition
        if (n == 0)
        {
            ans = max(cost, ans);
            return;
        }
        // Cut
        if (len >= n)
        {
            cost += price[n - 1];
            len -= n;
            solve(price, ans, cost, len, n);
            len += n;
            cost -= price[n - 1];
        }
        // Dont cut
        solve(price, ans, cost, len, n - 1);
    }

    int cutRod(vector<int> &price, int n)
    {
        int ans = INT_MIN, cost = 0;
        solve(price, ans, cost, n, n);
        return ans;
    }
};

int main()
{
    int n = 6;
    vector<int> price = {3, 5, 6, 7, 10, 12};

    Solution2 Obj1;
    cout << Obj1.cutRod(price, n);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}