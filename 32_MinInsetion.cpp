// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Given a string s. In one step you can insert any character at any 
// index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

#include <bits/stdc++.h>
using namespace std ;

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