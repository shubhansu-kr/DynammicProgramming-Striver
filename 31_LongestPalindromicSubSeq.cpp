// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

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

    Solution Obj1;
    cout << Obj1.longestPalindromeSubseq(s);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}