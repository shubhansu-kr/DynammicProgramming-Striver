// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Given a string s. In one step you can insert any character at any 
// index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

#include <bits/stdc++.h>
using namespace std ;

class Solution3
{
    // Using Longest Palindromic Subsequence
public:
    int longestPalindromeSubseq(string s)
    {
        // We just need to find the longest Palindromic subsequence 
        // in string s and rev(s);
        // Since we can insert anywhere in the string: Subseq 

        string t = s;
        reverse(s.begin(), s.end());

        int n = s.size();
        vector<int> cp(n + 1), xp(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == t[j - 1]) xp[j] = 1 + cp[j - 1];
                else xp[j] = max(xp[j - 1], cp[j]);
            }
            cp = xp;
        }
        return (n - cp[n]);
    }
};
class Solution2 {
    // Tabulation 
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n)); 

        int x = 1;
        while (x < n)
        {
            for (int i = 0, j = x; i < n && j < n; ++i, ++j)
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            ++x ;
        }
        return dp[0][n - 1];
    }
};

class Solution1 {
    // Recursion: Memoization
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        return solve(s, dp, 0, n-1);
    }
    int solve(string &s, vector<vector<int>> &dp, int i, int j) {
        if (i >= j) return 0 ;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = solve(s, dp, i+1, j-1);
        else return dp[i][j] = 1 + min(solve(s, dp, i+1, j), solve(s, dp, i, j-1));
    }
};

class Solution {
    // BruteForce: Recursion
public:
    int minInsertions(string s) {
        int n = s.length();
        return solve(s, 0, n-1);
    }
    int solve(string &s, int i, int j) {
        if (i >= j) return 0 ;
        if (s[i] == s[j]) return solve(s, i+1, j-1);
        else return 1 + min(solve(s, i+1, j), solve(s, i, j-1));
    }
};

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}