// https://leetcode.com/problems/unique-paths-ii/

// You are given an m x n integer array grid. There is a robot initially located
// at the top-left corner (i.e., grid[0][0]). The robot tries to move to the
// bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either
// down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that
// the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach
// the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal
// to 2 * 109.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Tabulation : Space Optimisation  // Incomplete
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int left = 0 ;
                if (obstacleGrid[i][j]){
                    dp[j] = 0;
                }
                else {
                    dp[j] = left + dp[j];
                }
            }
            
        }        
    }
};

class Solution3
{
    // Tabulation
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i == 0)
                    {
                        if (j > 0)
                            dp[i][j] = dp[i][j - 1];
                    }
                    else if (j == 0 && i > 0)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution2
{
    // Recursion : Memoization
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(obstacleGrid, dp);
        return dp[m - 1][n - 1] = solve(obstacleGrid, dp);
    }
    int solve(vector<vector<int>> &obs, vector<vector<int>> &dp, int i = 0, int j = 0)
    {
        if (i == obs.size() - 1 && j == obs[0].size() - 1 && !obs[i][j])
        {
            return 1;
        }
        if (i >= obs.size() || j >= obs[0].size() || obs[i][j])
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        // Go down -> Go right
        return dp[i][j] = solve(obs, dp, i + 1, j) + solve(obs, dp, i, j + 1);
    }
};

class Solution1
{
    // Recursion Improved
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        return solve(obstacleGrid);
    }
    int solve(vector<vector<int>> &obs, int i = 0, int j = 0)
    {
        if (i == obs.size() - 1 && j == obs[0].size() - 1 && !obs[i][j])
        {
            return 1;
        }
        if (i >= obs.size() || j >= obs[0].size() || obs[i][j])
        {
            return 0;
        }
        // Go down -> Go right
        return solve(obs, i + 1, j) + solve(obs, i, j + 1);
    }
};

class Solution
{
    // Simple Recursion
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int ans = 0;
        solve(obstacleGrid, ans);
        return ans;
    }
    void solve(vector<vector<int>> &obs, int &ans, int i = 0, int j = 0)
    {
        if (i == obs.size() - 1 && j == obs[0].size() - 1)
        {
            ++ans;
            return;
        }
        if (i >= obs.size() || j >= obs[0].size() || obs[i][j])
        {
            return;
        }
        // Go down
        solve(obs, ans, i + 1, j);
        // Go right
        solve(obs, ans, i, j + 1);
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};

    Solution3 Obj1;
    cout << Obj1.uniquePathsWithObstacles(grid);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}