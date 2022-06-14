// https://leetcode.com/problems/cherry-pickup/

// You are given an n x n grid representing a field of cherries,
// each cell is one of three possible integers.

// 0 means the cell is empty, so you can pass through,
// 1 means the cell contains a cherry that you can pick up and
// pass through, or
// -1 means the cell contains a thorn that blocks your way.
// Return the maximum number of cherries you can collect by
// following the rules below:

// Starting at the position (0, 0) and reaching (n - 1, n - 1)
// by moving right or down through valid path cells (cells with value 0 or 1).
// After reaching (n - 1, n - 1), returning to (0, 0) by moving
// left or up through valid path cells.
// When passing through a path cell containing a cherry, you pick
// it up, and the cell becomes an empty cell 0.
// If there is no valid path between (0, 0) and (n - 1, n - 1),
// then no cherries can be collected.

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Recursive solution : Memoization // Wrong Solution 
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        return max(reachEnd(grid), 0);
    }
    int reachEnd(vector<vector<int>> &grid, int i = 0, int j = 0)
    {
        int flag = 0;
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return -(1e9);

        if (grid[i][j] == 1)
            grid[i][j] = 0, flag = 1;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            // reached first destination
            vector<vector<int>> cp(grid.size() - 1, vector<int>(grid[0].size() - 1, -1));
            return flag + reachBegin(grid, cp, grid.size() - 1, grid[0].size() - 1);
        }

        // Go right
        int r = flag + reachEnd(grid, i, j + 1);
        // Go down
        int d = flag + reachEnd(grid, i + 1, j);

        if (flag)
            grid[i][j] = 1;

        return max(r, d);
    }

    int reachBegin(vector<vector<int>> &grid, vector<vector<int>> &cp, int i = 0, int j = 0)
    {
        int flag = 0;
        if (i < 0 || j < 0 || grid[i][j] == -1)
            return -1e9;

        if (cp[i][j] != -1)
            return cp[i][j];

        if (grid[i][j] == 1)
            grid[i][j] = 0, flag = 1;

        if (i == 0 && j == 0)
        {
            // reached final destination
            return flag;
        }

        // Go left
        int l = flag + reachBegin(grid, cp, i, j - 1);
        // Go up
        int u = flag + reachBegin(grid, cp, i - 1, j);

        if (flag)
            grid[i][j] = 1;

        return cp[i][j] = max(l, u);
    }
};

class Solution1
{
    // Better recursive solution
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        return max(0, reachEnd(grid));
    }
    int reachEnd(vector<vector<int>> &grid, int i = 0, int j = 0)
    {
        int flag = 0;
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return -(1e9);
        if (grid[i][j] == 1)
            grid[i][j] = 0, flag = 1;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            // reached first destination
            return flag + reachBegin(grid, grid.size() - 1, grid[0].size() - 1);
        }

        // Go right
        int r = flag + reachEnd(grid, i, j + 1);
        // Go down
        int d = flag + reachEnd(grid, i + 1, j);

        if (flag)
            grid[i][j] = 1;

        return max(r, d);
    }
    int reachBegin(vector<vector<int>> &grid, int i = 0, int j = 0)
    {
        int flag = 0;
        if (i < 0 || j < 0 || grid[i][j] == -1)
            return -1e9;
        if (grid[i][j] == 1)
            grid[i][j] = 0, flag = 1;

        if (i == 0 && j == 0)
        {
            // reached final destination
            return flag;
        }

        // Go left
        int l = flag + reachBegin(grid, i, j - 1);
        // Go up
        int u = flag + reachBegin(grid, i - 1, j);

        if (flag)
            grid[i][j] = 1;

        return max(l, u);
    }
};

class Solution
{
    // Recursive solution
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MIN, curr = 0;
        reachEnd(grid, ans, curr);
        return (ans == INT_MIN ? 0 : ans);
    }
    void reachEnd(vector<vector<int>> &grid, int &ans, int &curr, int i = 0, int j = 0)
    {
        int flag = 0;
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
        {
            return;
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            // reached destination
            reachBegin(grid, ans, curr, grid.size() - 1, grid[0].size() - 1);
            return;
        }

        if (grid[i][j] == 1)
        {
            ++curr;
            grid[i][j] = 0;
            flag = 1;
        }
        // Go right
        reachEnd(grid, ans, curr, i, j + 1);
        // Go down
        reachEnd(grid, ans, curr, i + 1, j);
        if (grid[i][j] == 0 && flag)
        {
            --curr;
            grid[i][j] = 1;
        }
    }
    void reachBegin(vector<vector<int>> &grid, int &ans, int &curr, int i = 0, int j = 0)
    {
        int flag = 0;
        if (i < 0 || j < 0 || grid[i][j] == -1)
        {
            return;
        }
        if (i == 0 && j == 0)
        {
            // reached destination
            ans = max(ans, curr);
            return;
        }

        if (grid[i][j] == 1)
        {
            ++curr;
            grid[i][j] = 0;
            flag = 1;
        }
        // Go left
        reachBegin(grid, ans, curr, i, j - 1);
        // Go up
        reachBegin(grid, ans, curr, i - 1, j);
        if (grid[i][j] == 0 && flag)
        {
            --curr;
            grid[i][j] = 1;
        }
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    vector<vector<int>> grid1 = {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};

    // [[1,1,-1],[1,-1,1],[-1,1,1]]

    Solution2 Obj1;
    cout << Obj1.cherryPickup(grid);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}