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
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    Solution Obj1;
    cout << Obj1.uniquePathsWithObstacles(grid);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}