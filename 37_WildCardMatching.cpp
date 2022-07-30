// https://leetcode.com/problems/wildcard-matching/

// Given an input string (s) and a pattern (p), implement wildcard pattern matching
// with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

#include <bits/stdc++.h>
using namespace std;

class soluiton3
{
    // Recursion: Memoization  
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, p, dp, m-1, n-1);
    }

    bool solve(string &s, string &p, vector<vector<int>> &dp, int i, int j) {
        if (j == -1) return i == -1;
        if (i == -1)
        {
            while (j > -1)
            {
                if (p[j] != '*'){return false;}
                --j;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(s, p, dp, i - 1, j - 1);
        if (p[j] == '*') return dp[i][j] = (solve(s, p, dp, i-1, j) || solve (s, p, dp, i, j-1));
            
        return dp[i][j] = false;
    }
};

class soluiton2
{
    // Recursion 
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        return solve(s, p, m-1, n-1);
    }

    bool solve(string &s, string &p, int i, int j) {
        if (j == -1) return i == -1;
        if (i == -1)
        {
            while (j > -1)
            {
                if (p[j] != '*'){return false;}
                --j;
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?') return solve(s, p, i - 1, j - 1);
        if (p[j] == '*') return (solve(s, p, i-1, j) || solve (s, p, i, j-1));
            
        return false;
    }
};

class Solution1
{
    // Tabulation : Wrong Solution
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.length(); ++i)
        {
            if (p[i - 1] == '*')
            {
                dp[0][i] = true;
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i < s.length(); ++i)
        {
            for (int j = 1; j < p.length(); ++j)
            {
                if (s[i - 1] == p[j - 1] || p[j] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j] == '*')
                    for (int k = 0; k <= i; ++k)
                    {
                        if (dp[i - k][j - 1])
                            dp[i][j] = true;
                    }
                else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};

class Solution1
{
    // Recursion: Memoization
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, p, dp, m - 1, n - 1);
    }

    bool solve(string &s, string &p, vector<vector<int>> &dp, int i, int j)
    {

        if (j == -1) return i == -1;
        if (i == -1)
        {
            while (j > -1)
            {
                if (p[j] != '*'){return false;}
                --j;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(s, p, dp, i - 1, j - 1);
        if (p[j] == '*') for (int k = 0; k <= i + 1; ++k) {if (solve(s, p, dp, i - k, j - 1)) return dp[i][j] = true;}
        return dp[i][j] = false;
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        return solve(s, p, m - 1, n - 1);
    }

    bool solve(string &s, string &p, int i, int j)
    {

        if (j == -1)
            return i == -1;
        if (i == -1)
            return j == -1;

        if (s[i] == p[j] || p[j] == '?')
            return solve(s, p, i - 1, j - 1);
        if (p[j] == '*')
            for (int k = 0; k <= i + 1; ++k)
            {
                if (solve(s, p, i - k, j - 1))
                    return true;
            }
        return false;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}