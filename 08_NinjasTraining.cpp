// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any
// one of these three activities. (Running, Fighting Practice or Learning New Moves).
// Each activity has some merit points on each day. As Ninja has to improve all his skills,
// he can’t do the same activity in two consecutive days. Can you help Ninja find out the
// maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day
// and activity. Your task is to calculate the maximum number of merit points that Ninja
// can earn.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Tabulation
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4,0));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], points[0][1], points[0][2]);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (k != j) {
                        int point = points[i][k] + dp[i-1][k];
                        dp[i][j] = max(dp[i][j], point); 
                    }
                }
            }           
        }
        return dp[n-1][3]; 
    }
};

class Solution3
{
    // Recursive solution : Memoization
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(n - 1, points, dp);
    }
    int solve(int n, vector<vector<int>> &points, vector<vector<int>> &dp, int k = -1)
    {
        if (n < 0)
        {
            return 0;
        }
        int subMax = INT_MIN;
        for (int j = 0; j < 3; ++j)
        {
            if (k == j)
                continue;
            if (dp[n][j] == -1)
            {
                dp[n][j] = (points[n][j] + solve(n - 1, points, dp, j));
            }
            subMax = max(subMax, dp[n][j]);
        }
        return subMax;
    }
};

class Solution2
{
    // Recursive solution : Improved
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        int ans = INT_MIN, credits = 0;
        return solve(n - 1, points);
    }
    int solve(int n, vector<vector<int>> &points, int k = -1)
    {
        if (n < 0)
        {
            return 0;
        }
        int subMax = INT_MIN;
        for (int j = 0; j < 3; ++j)
        {
            if (k == j)
                continue;
            subMax = max(subMax, (points[n][j] + solve(n - 1, points, j)));
        }
        return subMax;
    }
};

class Solution1
{
    // Recursive solution : N as parameter
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        int ans = INT_MIN, credits = 0;
        solve(n - 1, points, ans, credits);
        return ans;
    }
    void solve(int n, vector<vector<int>> &points, int &ans, int &credits, int k = -1)
    {
        if (n < 0)
        {
            ans = max(ans, credits);
            return;
        }
        for (int j = 0; j < 3; ++j)
        {
            if (k == j)
                continue;
            credits += points[n][j];
            solve(n - 1, points, ans, credits, j);
            credits -= points[n][j];
        }
    }
};

class Solution
{
    // Recursive solution
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        int ans = INT_MIN, credits = 0;
        solve(n, points, ans, credits);
        return ans;
    }
    void solve(int &n, vector<vector<int>> &points, int &ans, int &credits, int k = -1, int i = 0)
    {
        if (i >= n)
        {
            ans = max(ans, credits);
            return;
        }
        for (int j = 0; j < 3; ++j)
        {
            if (k == j)
                continue;
            credits += points[i][j];
            solve(n, points, ans, credits, j, i + 1);
            credits -= points[i][j];
        }
    }
};

int main()
{
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

    Solution4 Obj1;
    cout << Obj1.ninjaTraining(3, points);

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    return 0;
}