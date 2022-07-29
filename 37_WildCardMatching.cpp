// https://leetcode.com/problems/wildcard-matching/

// Given an input string (s) and a pattern (p), implement wildcard pattern matching 
// with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

#include <bits/stdc++.h>
using namespace std ;

class Solution 
{
    // BruteForce: Recursion
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        return solve(s, p, m-1, n-1);
    }

    bool solve(string &s, string &p, int i, int j) {

        if (j == -1) return i == -1;
        if (i == -1) return j == -1;

        if(s[i] == p[j] || p[j] == '?') return solve(s, p, i-1, j-1);
        if(p[j] == '*') for (int k = 0; k <= i+1; ++k){if (solve(s, p, i-k, j-1)) return true;}
        return false;
    }

};

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}