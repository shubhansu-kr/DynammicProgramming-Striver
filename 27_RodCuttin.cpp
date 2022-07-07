// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each
// size has a cost associated with it. Determine the maximum cost obtained by cutting
// the rod and selling its pieces.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce: Recursion
public:
    void solve(vector<int> &price, int &ans, int &cost, int &len, int n)
    {
        // base condition
        if (n == 0)
        {
            ans = max(cost, ans);
            return;
        }
        // Cut
        if (len >= n)
        {
            cost += price[n - 1];
            len -= n;
            solve(price, ans, cost, len, n);
            len += n;
            cost -= price[n - 1];
        }
        // Dont cut
        solve(price, ans, cost, len, n - 1);
    }

    int cutRod(vector<int> &price, int n)
    {
        int ans = INT_MIN, cost = 0;
        solve(price, ans, cost, n, n);
        return ans;
    }
};

int main()
{
    int n = 6;
    vector<int> price = {3, 5, 6, 7, 10, 12};

    Solution Obj1;
    cout << Obj1.cutRod(price, n);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}