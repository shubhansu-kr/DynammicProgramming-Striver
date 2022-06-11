// https://leetcode.com/problems/minimum-path-sum/

// Given a m x n grid filled with non-negative numbers, find a path
// from top left to bottom right, which minimizes the sum of all numbers
// along its path.

// Note: You can only move either down or right at any point in time.

#include <bits/stdc++.h>
using namespace std;

class Solution4 {
    // Tabulation : Space optimisation
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n);
        for (int i = 0; i < m; ++i)
        {
            vector<int> curr(n);
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    curr[j] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;
                    int left = grid[i][j];
                    if (j > 0)
                        left += curr[j-1];
                    else
                        up += 1e9;

                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

class Solution3
{
    // Tabulation
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up += 1e9;
                    int left = grid[i][j];
                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        up += 1e9;

                    dp[i][j] = min(left, up);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution2
{
    // Recursive solution : Memoization
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, dp, m - 1, n - 1);
    }
    int solve(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n)
    {
        if (m < 0 || n < 0)
            return 1e9;
        if (m == 0 && n == 0)
            return grid[0][0];
        if (dp[m][n] != -1)
            return dp[m][n];
        int l = solve(grid, dp, m, n - 1) + grid[m][n];
        int u = solve(grid, dp, m - 1, n) + grid[m][n];
        return dp[m][n] = min(l, u);
    }
};

class Solution1
{
    // Recursive solution : m, n as parameters
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        return solve(grid, m - 1, n - 1);
    }
    int solve(vector<vector<int>> &grid, int m, int n)
    {
        if (m < 0 || n < 0)
            return 1e9;
        if (m == 0 && n == 0)
            return grid[0][0];
        int l = solve(grid, m, n - 1) + grid[m][n];
        int u = solve(grid, m - 1, n) + grid[m][n];
        return min(l, u);
    }
};

class Solution
{
    // Recursive solution
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        return solve(grid);
    }
    int solve(vector<vector<int>> &grid, int i = 0, int j = 0)
    {
        if (i >= grid.size() || j >= grid[0].size())
            return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];
        cout << i << " " << j << endl;
        int r = solve(grid, i, j + 1) + grid[i][j];
        int d = solve(grid, i + 1, j) + grid[i][j];
        cout << r << " " << d << endl;
        return min(r, d);
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution4 Obj1;
    cout << Obj1.minPathSum(grid);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}