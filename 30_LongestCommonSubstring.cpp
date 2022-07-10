// https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?leftPanelTab=0

// You have been given two strings 'STR1' and 'STR2'. You have to find the length of the
// longest common substring.
// A string “s1” is a substring of another string “s2” if “s2” contains the same characters
// as in “s1”, in the same order and in continuous fashion also.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Print the longest common substring
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        int ans = INT_MIN;
        int x, y;
        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = 0;
                
                if (ans < dp[i][j]) {
                    ans = dp[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        int len = ans;
        string lcs(len, '_');

        while (x && y && dp[x][y]) {
            lcs[--len] = text1[x-1];
            --x, --y;
        }
        
        cout << lcs;
        return 0; 
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        int ans = INT_MIN;
        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main()
{

    string text1 = "apple", text2 = "rampageapple";

    Solution1 Obj1;
    Obj1.longestCommonSubsequence(text1, text2);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}