// https://leetcode.com/problems/edit-distance/

// Given two strings word1 and word2, return the minimum number of operations required
// to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursion: Memoization
    // horse ros
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(word1, word2, dp, m-1, n-1);
    }

    int solve(string &s, string &t, vector<vector<int>> &dp, int i, int j)
    {
        if (j == -1){return i+1;}

        if (dp[i][j] != -1) return dp[i][j];

        if (i >= 0 && s[i] == t[j]) return dp[i][j] = solve(s, t, dp, i - 1, j - 1);

        int del = INT_MAX;
        if (i >= 0){del = 1 + solve(s, t, dp, i - 1, j);}
        int rep = INT_MAX;
        if (i >= 0){rep = 1 + solve(s, t, dp, i - 1, j - 1);}
        int ins = 1 + solve(s, t, dp, i, j - 1);
        int dup = min(del, rep);
        return dp[i][j] = min(dup , ins);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        return solve(word1, word2, m-1, n-1);
    }

    int solve(string &s, string &t, int i, int j)
    {
        if (j == -1){return i+1;}
        if ( i >= 0 && s[i] == t[j]) return solve(s, t, i - 1, j - 1);

        int del = INT_MAX;
        if (i >= 0){del = 1 + solve(s, t, i - 1, j);}
        int rep = INT_MAX;
        if (i >= 0){rep = 1 + solve(s, t, i - 1, j - 1);}
        int ins = 1 + solve(s, t, i, j - 1);
        int dup = min(del, rep);
        return min(dup , ins);
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}