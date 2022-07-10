// Print the longest common subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j)
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        int len = dp[n1][n2];
        string ans(len, '#');
        while (n1 && n2){
            if (text1[n1 - 1] == text2[n2 - 1]){ans[--len] = text1[n1 - 1];--n1, --n2;}
            else{if (dp[n1 - 1][n2] > dp[n1][n2 - 1]){--n1;}else{--n2;}}
        }
        cout << ans;
        return 0;
    }
};

class Solution
{
    // Top Down
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j)
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        int len = dp[n1][n2];
        string ans(len, '#');
        while (n1 && n2){
            if (text1[n1 - 1] == text2[n2 - 1]){ans[--len] = text1[n1 - 1];--n1, --n2;}
            else{if (dp[n1 - 1][n2] > dp[n1][n2 - 1]){--n1;}else{--n2;}}
        }
        cout << ans;
        return 0;
    }
};

int main()
{
    string text1 = "badc", text2 = "ace";

    Solution Obj1;
    Obj1.longestCommonSubsequence(text1, text2);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}