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

class Solution1
{
    // Recursion: Memoization 
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
        if (dp[n1][n2] != -1) return dp[n1][n2];

        // Match
        if (s1[n1] == s2[n2])
        {
            return 1 + solve(s1, s2, dp, n1 - 1, n2 - 1);
        }
        else
        {
            return max(solve(s1, s2, dp, n1, n2 - 1), solve(s1, s2, dp, n1 - 1, n2));
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

    string text1 = "bdf", text2 = "ace";

    Solution Obj1;
    cout << Obj1.longestCommonSubsequence(text1, text2);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}