// https://leetcode.com/problems/longest-common-subsequence/

// Given two strings text1 and text2, return the length of their longest
// common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original
// string with some characters (can be none) deleted without changing the
// relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to
// both strings.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Tabulation: Index Shifting: Space Optimisation
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> cp(n2 + 1), xp(n2 + 1);

        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (text1[i - 1] == text2[j - 1]) xp[j] = 1 + cp[j - 1];
                else xp[j] = max(xp[j - 1], cp[j]);
            }
            cp = xp;
        }
        return cp[n2];
    }
};

class Solution3
{
    // Tabulation: Index Shifting
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j)
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

        return dp[n1][n2];
    }
};

class Solution2
{
    // Tabulation
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2));

        int ind = text2.find(text1[0]);
        if (ind != string::npos)
            for (int i = ind; i < n2; ++i)
                dp[0][i] = 1;
        ind = text1.find(text2[0]);
        if (ind != string::npos)
            for (int i = ind; i < n1; ++i)
                dp[i][0] = 1;

        for (int i = 1; i < n1; ++i)
            for (int j = 1; j < n2; ++j)
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

        return dp[n1 - 1][n2 - 1];
    }
};

class Solution1
{
    // Recursion: Memoization : TLE
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(text1, text2, dp, n1 - 1, n2 - 1);
    }
    int solve(string &s1, string &s2, vector<vector<int>> &dp, int n1, int n2)
    {
        // Base condition
        if (n1 == -1 || n2 == -1)
            return 0;

        // Dp
        if (dp[n1][n2] != -1)
            return dp[n1][n2];

        // Match
        if (s1[n1] == s2[n2])
        {
            return dp[n1][n2] = 1 + solve(s1, s2, dp, n1 - 1, n2 - 1);
        }
        else
        {
            return dp[n1][n2] = max(solve(s1, s2, dp, n1, n2 - 1), solve(s1, s2, dp, n1 - 1, n2));
        }
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        return solve(text1, text2, n1 - 1, n2 - 1);
    }
    int solve(string &s1, string &s2, int n1, int n2)
    {
        // Base condition
        if (n1 == -1 || n2 == -1)
            return 0;

        // Match
        if (s1[n1] == s2[n2])
        {
            return 1 + solve(s1, s2, n1 - 1, n2 - 1);
        }
        else
        {
            return max(solve(s1, s2, n1, n2 - 1), solve(s1, s2, n1 - 1, n2));
        }
    }
};

int main()
{

    string text1 = "bd", text2 = "ace";

    Solution3 Obj1;
    cout << Obj1.longestCommonSubsequence(text1, text2);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}