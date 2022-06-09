// https://leetcode.com/problems/unique-paths/

// There is a robot on an m x n grid. The robot is initially located at the top-left corner
// (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1]
// [n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the
// robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursive solution : Improved 
public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1)
            return 0;
        if (m == 1 && n == 1)
        {
            return 1;
        }
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

class Solution
{
    // Recursive solution
public:
    int uniquePaths(int m, int n)
    {
        int ans = 0;
        solve(m - 1, n - 1, ans);
        return ans;
    }
    void solve(int m, int n, int &ans)
    {
        if (m < 0 || n < 0)
            return;
        if (m == 0 && n == 0)
        {
            ++ans;
            return;
        }
        solve(m - 1, n, ans);
        solve(m, n - 1, ans);
    }
};

int main()
{
    Solution1 Obj1;
    cout << Obj1.uniquePaths(3, 7);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}