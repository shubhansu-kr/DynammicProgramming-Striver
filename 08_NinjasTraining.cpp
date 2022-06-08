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
    void solve(int n, vector<vector<int>> &points, int &ans, int &credits, int k = -1, int i = 0)
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

    Solution Obj1;
    cout << Obj1.ninjaTraining(3, points);

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    return 0;
}