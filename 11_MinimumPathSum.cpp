// https://leetcode.com/problems/minimum-path-sum/

// Given a m x n grid filled with non-negative numbers, find a path
// from top left to bottom right, which minimizes the sum of all numbers
// along its path.

// Note: You can only move either down or right at any point in time.

#include <bits/stdc++.h>
using namespace std;

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
            return ;
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

    Solution1 Obj1;
    cout << Obj1.minPathSum(grid);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}