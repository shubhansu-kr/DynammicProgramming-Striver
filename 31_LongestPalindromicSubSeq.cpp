// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation : Reverse string 
public:
    int longestPalindromeSubseq(string s)
    {
        // We just need to find the longest common subsequence 
        // in string s and rev(s);

        string t = s;
        reverse(s.begin(), s.end());

        int n1 = s.size(), n2 = t.size();
        vector<int> cp(n2 + 1), xp(n2 + 1);

        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (s[i - 1] == t[j - 1]) xp[j] = 1 + cp[j - 1];
                else xp[j] = max(xp[j - 1], cp[j]);
            }
            cp = xp;
        }
        return cp[n2];
    }
};

class Solution2
{
    // Tabulation
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        int x = 1;
        while (x < n)
        {
            for (int i = 0, j = x; i < n && j < n; ++i, ++j)
            {
                if (s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
            ++x ;
        }
        return dp[0][n - 1];
    }
};

class Solution1
{
    // Recursion: Memoization
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, dp, 0, n - 1);
    }
    int solve(string &s, vector<vector<int>> &dp, int i, int j)
    {
        if (i == j) return 1;
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) return dp[i][j] = 2 + solve(s, dp, i + 1, j - 1);
        else return dp[i][j] = max(solve(s, dp, i + 1, j), solve(s, dp, i, j - 1));
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        return solve(s, 0, n - 1);
    }
    int solve(string &s, int i, int j)
    {
        if (i == j) return 1;
        if (i > j) return 0;
        if (s[i] == s[j]) return 2 + solve(s, i + 1, j - 1);
        else return max(solve(s, i + 1, j), solve(s, i, j - 1));
    }
};

int main()
{

    string s = "bbbabs";

    Solution2 Obj1;
    cout << Obj1.longestPalindromeSubseq(s);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}