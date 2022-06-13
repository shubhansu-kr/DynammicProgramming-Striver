// https://leetcode.com/problems/triangle/

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below.
// More formally, if you are on index i on the current row, you may move
// to either index i or index i + 1 on the next row.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation : Space Optimised
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<int> x(m, INT_MAX);
        x[0] = triangle[0][0];
        for (int i = 1; i < m; ++i)
        {
            vector<int> temp(m);
            for (int j = 0; j < i + 1; ++j)
            {
                int up = INT_MAX;
                if (j < i)
                {
                    up = triangle[i][j] + x[j];
                }
                int left = INT_MAX;
                if (j > 0)
                {
                    left = triangle[i][j] + x[j - 1];
                }
                temp[j] = min(up, left);
            }
            x = temp;
        }
        int ans = INT_MAX;
        for (int &a : x)
        {
            ans = min(ans, a);
        }
        return ans;
    }
};

class Solution2
{
    // Tabulation
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));
        dp[0][0] = triangle[0][0];
        int mini;
        for (int i = 1; i < m; ++i)
        {
            mini = INT_MAX;
            for (int j = 0; j < i + 1; ++j)
            {
                int up = INT_MAX;
                if (j < i)
                {
                    up = triangle[i][j] + dp[i - 1][j];
                }
                int left = INT_MAX;
                if (j > 0)
                {
                    left = triangle[i][j] + dp[i - 1][j - 1];
                }

                dp[i][j] = min(up, left);
                mini = min(dp[i][j], mini);
            }
        }
        return mini;
    }
};

class Solution1
{
    // Recursion : Memoization
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        solve(triangle, dp);
        return dp[0][0];
    }
    int solve(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i = 0, int j = 0)
    {
        if (i == triangle.size())
            return 0;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        // Down
        int d = triangle[i][j] + solve(triangle, dp, i + 1, j);
        // Right
        int r = triangle[i][j] + solve(triangle, dp, i + 1, j + 1);

        return dp[i][j] = min(d, r);
    }
};

class Solution
{
    // Recursion
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return solve(triangle);
    }
    int solve(vector<vector<int>> &triangle, int i = 0, int j = 0)
    {
        if (i == triangle.size())
            return 0;

        // Down
        int d = triangle[i][j] + solve(triangle, i + 1, j);
        // Right
        int r = triangle[i][j] + solve(triangle, i + 1, j + 1);
        return min(d, r);
    }
};

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    Solution3 obj1;
    cout << obj1.minimumTotal(triangle);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}