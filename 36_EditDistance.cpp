// https://leetcode.com/problems/edit-distance/

// Given two strings word1 and word2, return the minimum number of operations required
// to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation : Space Optimisation 
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<int> curr(n+1), prev(n+1);
        for (int j = 0; j <= n; ++j){prev[j] = j;}
        for (int i = 1; i <= m; ++i){
            curr[0] = i;
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
                else {
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j - 1];
                    int ins = 1 + curr[j - 1];
                    int dup = min(del, rep);
                    curr[j] = min(dup , ins);
                }
            }
            prev = curr;
        }
        return curr[n];
    }
};


class Solution2 
{
    // Tabulation 
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

        for (int i = 0; i <= m; ++i){dp[i][0] = i+1;}
        for (int j = 0; j <= n; ++j){dp[0][j] = j+1;}
        
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    int del = 1 + dp[i - 1][j];
                    int rep = 1 + dp[i - 1][j - 1];
                    int ins = 1 + dp[i][j - 1];
                    int dup = min(del, rep);
                    dp[i][j] = min(dup , ins);
                }
            }
        return dp[m][n];
    }
};

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
        if (i == -1){return j+1;}

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = solve(s, t, dp, i - 1, j - 1);

        int del = 1 + solve(s, t, dp, i - 1, j);
        int rep = 1 + solve(s, t, dp, i - 1, j - 1);
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