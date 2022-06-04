// Fibonacci Sequence Using DP

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Tabulation : Bottoms UP
    // Time complexity : O(N);
    // Space Complexity : O(N) + O(N) ;
public:
    int fibonacci(int n)
    {
        vector<int> dp(n);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i < n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << dp[i]<< " " ;
        }
        cout << endl;
        return dp[n-1];
    }
};

class Solution
{
    // Memoization approach : top Down
    // Time complexity : O(N);
    // Space Complexity : O(N) + O(N) ;
public:
    int fibonacci(int n)
    {
        vector<int> dp(n, -1);
        solve(n, dp);
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
};

int main()
{
    Solution1 obj1;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonnaci n is : " << obj1.fibonacci(n) << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}