// https://leetcode.com/problems/cherry-pickup-ii/

// You are given a rows x cols matrix grid representing a field of cherries where
// grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following
// the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell
// becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation : Space Optimisation
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    cp[i][j] = grid[m - 1][j];
                }
                else
                {
                    cp[i][j] = grid[m - 1][j] + grid[m - 1][i];
                }
            }
        }

        // Tabulation starts (from m-2 to 0)
        for (int i = m - 2; i >= 0; --i)
        {
            vector<vector<int>> temp(n, vector<int>(n));
            for (int j1 = 0; j1 < n; ++j1)
            {
                for (int j2 = 0; j2 < n; ++j2)
                {
                    int subMax = INT_MIN;
                    // Loop through possibilites
                    for (int x = -1; x < 2; ++x)
                    {
                        for (int y = -1; y < 2; ++y)
                        {
                            // Check for common cell
                            int val = 0;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            //
                            if (j1 + x >= 0 && j2 + y >= 0 && j1 + x < n && j2 + y < n)
                                val += cp[j1 + x][j2 + y];
                            else
                                val += -1e5;
                            subMax = max(subMax, val);
                        }
                    }
                    temp[j1][j2] = subMax;
                }
            }
            cp = temp;
        }
        return cp[0][n - 1];
    }
};

class Solution2
{
    // Tabulation
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n)));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    dp[m - 1][i][j] = grid[m - 1][j];
                }
                else
                {
                    dp[m - 1][i][j] = grid[m - 1][j] + grid[m - 1][i];
                }
            }
        }

        // Tabulation starts (from m-2 to 0)
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j1 = 0; j1 < n; ++j1)
            {
                for (int j2 = 0; j2 < n; ++j2)
                {
                    int subMax = INT_MIN;
                    // Loop through possibilites
                    for (int x = -1; x < 2; ++x)
                    {
                        for (int y = -1; y < 2; ++y)
                        {
                            // Check for common cell
                            int val = 0;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            //
                            if (j1 + x >= 0 && j2 + y >= 0 && j1 + x < n && j2 + y < n)
                                val += dp[i + 1][j1 + x][j2 + y];
                            else
                                val += -1e5;
                            subMax = max(subMax, val);
                        }
                    }
                    dp[i][j1][j2] = subMax;
                }
            }
        }
        return dp[0][0][n - 1];
    }
};

class Solution1
{
    // Recursive solution : Memoization
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, dp, 0, 0, grid[0].size() - 1);
    }
    int solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int i = 0, int j1 = 0, int j2 = 0)
    {
        // Base Condition - Out of bound || Reached destination

        // Out of bound
        if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
        {
            return -1e9;
        }
        // Reached Destination
        if (i == grid.size() - 1)
        {
            // Check for common cell
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }
        int subMax = INT_MIN;

        // Loop through possibilites
        for (int x = -1; x < 2; ++x)
        {
            for (int y = -1; y < 2; ++y)
            {
                // Check for common cell
                if (j1 == j2)
                {
                    subMax = max(subMax, grid[i][j1] + solve(grid, dp, i + 1, j1 + x, j2 + y));
                }
                else
                {
                    subMax = max(subMax, grid[i][j1] + grid[i][j2] + solve(grid, dp, i + 1, j1 + x, j2 + y));
                }
            }
        }
        return dp[i][j1][j2] = subMax;
    }
};

class Solution
{
    // Recursive solution
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        return solve(grid, 0, 0, grid[0].size() - 1);
    }
    int solve(vector<vector<int>> &grid, int i = 0, int j1 = 0, int j2 = 0)
    {
        // Base Condition - Out of bound || Reached destination

        // Out of bound
        if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
        {
            return -1e9;
        }
        cout << i << " " << j1 << " " << j2 << " " << endl;
        // Reached Destination
        if (i == grid.size() - 1)
        {
            // Check for common cell
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        int subMax = INT_MIN;

        // Loop through possibilites
        for (int x = -1; x < 2; ++x)
        {
            for (int y = -1; y < 2; ++y)
            {
                // Check for common cell
                if (j1 == j2)
                {
                    subMax = max(subMax, grid[i][j1] + solve(grid, i + 1, j1 + x, j2 + y));
                }
                else
                {
                    subMax = max(subMax, grid[i][j1] + grid[i][j2] + solve(grid, i + 1, j1 + x, j2 + y));
                }
            }
        }
        return subMax;
    }
};

int main()
{
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}, {3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

    Solution3 obj1;
    cout << obj1.cherryPickup(grid);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}