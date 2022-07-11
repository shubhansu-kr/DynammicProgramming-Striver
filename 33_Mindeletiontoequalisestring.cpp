// https://leetcode.com/problems/delete-operation-for-two-strings/

// Given two strings word1 and word2, return the minimum number of steps
// required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation : Space Optimised 
public:
    int minDistance(string word1, string word2) {
        int  n1 = word1.size(), n2 = word2.size();
        vector<int> curr(n2+1), temp(n2+1);     
        for (int i = 1; i <= n1; ++i){
            for (int j = 1; j <= n2; ++j) {
                if (word1[i-1] == word2[j-1]) temp[j] = 1 + curr[j-1];
                else temp[j] = max(curr[j], temp[j-1]);  
            }
            curr = temp;     
        }
        int lcs = curr[n2];
        return (n1 + n2 - 2*lcs);
    }
};

class Solution2
{
    // Tabulation 
public:
    int minDistance(string word1, string word2) {
        int  n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));     
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j) 
                if (word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);       
        int lcs = dp[n1][n2];
        return (n1 + n2 - 2*lcs);
    }
};

class Solution1
{
    // Recursion: Memoization  
public:
    int minDistance(string word1, string word2) {
        int  n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));      
        int lcs = solve(word1, word2, dp);
        return (n1 + n2 - 2*lcs);
    }
    
    int solve(string &word1, string &word2,vector<vector<int>> &dp, int i=0, int j = 0) {
        if (i == word1.size() || j == word2.size()) return 0; 
        if (dp[i][j] != -1) return dp[i][j]; 
        if (word1[i] == word2[j]) return dp[i][j] = 1 + solve(word1, word2, dp, i+1, j+1);
        else return dp[i][j] = max(solve(word1, word2, dp, i+1, j), solve(word1, word2, dp, i, j+1));
    }
};

class Solution
{
    // BruteForce: Recursion 
public:
    int minDistance(string word1, string word2) {
        int lcs = solve(word1, word2), n1 = word1.size(), n2 = word2.size();
        return (n1 + n2 - 2*lcs);
    }
    
    int solve(string &word1, string &word2, int i=0, int j = 0) {
        if (i == word1.size() || j == word2.size()) return 0; 

        if (word1[i] == word2[j]) return 1 + solve(word1, word2, i+1, j+1);
        else return max(solve(word1, word2, i+1, j), solve(word1, word2, i, j+1));
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}