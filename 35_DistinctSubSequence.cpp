// https://leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution7
{
    // Tabulation: space optimised : SIngle Array
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s == t;
        vector<double> cp(t.length()+1);
        cp[0] = 1;
        for (int i = 1; i <= s.length(); ++i)
            for (int j = t.length(); j >= 1; --j)
                if (s[i-1] == t[j-1]) cp[j] = cp[j-1] + cp[j];
        return (int)cp[t.length()];
    }
};

class Solution6
{
    // Tabulation: space optimised 
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s == t;
        vector<double> cp(t.length()+1), xp(t.length()+1);

        cp[0] = xp[0] = 1;

        for (int i = 1; i <= s.length(); ++i)
        {
            for (int j = 1; j <= t.length(); ++j)
            {
                if (s[i-1] == t[j-1]) xp[j] = cp[j-1] + cp[j];
                else xp[j] = cp[j];
            }   
            cp = xp;
        }
        return (int)cp[t.length()];
    }
};

class Solution5
{
    // Tabulation:   
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s == t;
        vector<vector<double>> dp(s.length()+1, vector<double> (t.length()+1, 0));        

        for (int i = 0; i <= s.length(); ++i) dp[i][0] = 1;        
        for (int i = 1; i <= s.length(); ++i)
        {
            for (int j = 1; j <= t.length(); ++j)
            {
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }   
        }
        return (int)dp[s.length()][t.length()];
    }
};

class Solution4
{
    // Recursion: Memoization: Bottom up  
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s == t;
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        return solve(s, t, dp, s.length()-1, t.length()-1);
    }

    int solve(string &s, string &t,vector<vector<int>> &dp, int i, int j)
    {
        if (j == -1 || i == -1) return j == -1;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = solve(s, t, dp, i - 1, j - 1) + solve(s, t, dp, i - 1, j);
        else return dp[i][j] = solve(s, t, dp, i - 1, j);
    }
};

class Solution3
{
    // Recursion: Memoization 
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s == t;
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        return solve(s, t, dp);
    }

    int solve(string &s, string &t,vector<vector<int>> &dp, int i = 0, int j = 0)
    {
        if (j == t.length() || i == s.length()) return j == t.length();
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = solve(s, t, dp, i + 1, j + 1) + solve(s, t, dp, i + 1, j);
        else return dp[i][j] = solve(s, t, dp, i + 1, j);
    }
};

class Solution2
{
    // Recursion: Two pointer 
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s.length() == t.length();
        return solve(s, t);
    }

    int solve(string &s, string &t, int i = 0, int j = 0)
    {
        if (j == t.length() || i == s.length()) return j == t.length();
        
        if (s[i] == t[j]) return solve(s, t, i + 1, j + 1) + solve(s, t, i + 1, j);
        else return solve(s, t, i + 1, j);
    }
};

class Solution1
{
    // Recursion
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s.length() == t.length();

        int ans = 0;
        string sub;
        return solve(s, t, sub, ans);
    }

    int solve(string &s, string &t, string &sub, int i = 0)
    {
        if (i == s.length())
        {
            if (sub == t) return 1;
            return 0;
        }

        // Pick
        sub.push_back(s[i]);
        int pick = solve(s, t, sub, i + 1);
        sub.pop_back();

        // Dont Pick
        int noPick = solve(s, t, sub, i + 1);

        return pick + noPick;
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length())
            return s.length() == t.length();

        int ans = 0;
        string sub;
        solve(s, t, sub, ans);
        return ans;
    }
    void solve(string &s, string &t, string &sub, int &ans, int i = 0)
    {
        if (i == s.length())
        {
            if (sub == t)
                ++ans;
            return;
        }

        // Pick
        sub.push_back(s[i]);
        solve(s, t, sub, ans, i + 1);
        sub.pop_back();

        // Dont Pick
        solve(s, t, sub, ans, i + 1);
    }
};

int main()
{
    string s = "babgbag", t = "bag";

    Solution5 Obj1;
    cout << Obj1.numDistinct(s, t);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}