// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029

// You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with
// weight capacity ‘W’. You need to fill the knapsack with the items in such a way
// that you get the maximum profit. You are allowed to take one item multiple times.

#include <bits/stdc++.h>
using namespace std;
class Solution2
{
    // Recursion: Optimised
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        if (n == 0)
            return 0;
        if (w <= 0)
            return 0;

        int pick = 0;
        if (w >= weight[n - 1])
        {
            pick = profit[n - 1] + unboundedKnapsack(n, w - weight[n - 1], profit, weight);
        }
        int noPick = unboundedKnapsack(n - 1, w, profit, weight);
        return max(pick, noPick);
    }
};

class Solution1
{
    // Recursion: Optimised
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        return solve(profit, weight, w, n - 1);
    }
    int solve(vector<int> &profit, vector<int> &weight, int w, int n)
    {
        if (n == -1)
            return 0;
        if (w <= 0)
            return 0;

        int pick = 0;
        if (w >= weight[n])
        {
            pick = profit[n] + solve(profit, weight, w - weight[n], n);
        }
        int noPick = solve(profit, weight, w, n - 1);
        return max(pick, noPick);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        int ans = INT_MIN, totalProfit = 0;
        solve(profit, weight, ans, totalProfit, w, n - 1);
        return ans;
    }
    void solve(vector<int> &profit, vector<int> &weight, int &ans, int &totalProfit, int &w, int n)
    {
        // base condition
        if (n == -1)
        {
            ans = max(ans, totalProfit);
            return;
        }

        // pick
        if (weight[n] <= w)
        {
            totalProfit += profit[n];
            w -= weight[n];
            solve(profit, weight, ans, totalProfit, w, n);
            w += weight[n];
            totalProfit -= profit[n];
        }
        // noPick
        solve(profit, weight, ans, totalProfit, w, n - 1);
    }
};

int main()
{

    vector<int> profit = {3, 4, 5, 1}, weight = {4, 1, 2, 3};
    int n = 4, w = 7;

    Solution2 Obj1;
    cout << Obj1.unboundedKnapsack(n, w, profit, weight);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}