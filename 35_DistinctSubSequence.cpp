// https://leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce: Recursion
public:
    int numDistinct(string s, string t)
    {
        if (s.length() <= t.length()) return s.length() == t.length() ;

        int ans = 0;
        string sub;
        solve(s, t, sub, ans);
        return ans;
    }
    void solve(string &s, string &t, string &sub, int &ans, int i = 0)
    {
        if (i == s.length())
        {
            if (sub == t) ++ans;
            return;
        }

        // Pick
        sub.push_back(s[i]);
        solve(s, t, sub, ans, i+1);
        sub.pop_back();

        // Dont Pick
        solve(s, t, sub, ans, i+1);
    }
};

int main()
{
    string s = "rabbbit", t = "rabbit" ;

    Solution Obj1;
    cout << Obj1.numDistinct(s, t);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}