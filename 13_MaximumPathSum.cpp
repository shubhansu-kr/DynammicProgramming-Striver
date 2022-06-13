// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

// You have been given an N*M matrix filled with integer numbers, find the maximum sum
// that can be obtained from a path starting from any cell in the first row to any cell
// in the last row.

// From a cell in a row, you can move to another cell directly below that row, or
// diagonally below left or right. So from a particular cell (row, col), we can move
// in three directions i.e.
// Down: (row+1,col)
// Down left diagonal: (row+1,col-1)
// Down right diagonal: (row+1, col+1)

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursive : Memoization
public:
    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int subMax = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            dp[m - 1][i] = solve(matrix, dp, m - 1, i);
            subMax = max(subMax, dp[m - 1][i]);
        }
        return subMax;
    }
    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {
        if (i == 0)
        {
            return matrix[i][j];
        }

        if (dp[i][j] != -1) return dp[i][j];

        // up : ALways valid
        int up = matrix[i][j] + solve(matrix, dp, i - 1, j);
        // right : Valid for (j < n-1)
        int right = INT_MIN;
        if (j < matrix[0].size() - 1)
            right = matrix[i][j] + solve(matrix, dp, i - 1, j + 1);
        // left  : Valid for j > 0
        int left = INT_MIN;
        if (j > 0)
            left = matrix[i][j] + solve(matrix, dp, i - 1, j - 1);

        int ans = max(left, up);
        return dp[i][j] = max(ans, right);
    }
};

class Solution
{
    // Recursive solution
public:
    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int subMax = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            int x = solve(matrix, m - 1, i);
            subMax = max(subMax, x);
        }
        return subMax;
    }
    int solve(vector<vector<int>> &matrix, int i, int j)
    {
        if (i == 0)
        {
            return matrix[i][j];
        }

        // up : ALways valid
        int up = matrix[i][j] + solve(matrix, i - 1, j);
        // right : Valid for (j < n-1)
        int right = INT_MIN;
        if (j < matrix[0].size() - 1)
            right = matrix[i][j] + solve(matrix, i - 1, j + 1);
        // left  : Valid for j > 0
        int left = INT_MIN;
        if (j > 0)
            left = matrix[i][j] + solve(matrix, i - 1, j - 1);

        int ans = max(left, up);
        return max(ans, right);
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};

    Solution1 obj1;
    cout << obj1.getMaxPathSum(matrix);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}