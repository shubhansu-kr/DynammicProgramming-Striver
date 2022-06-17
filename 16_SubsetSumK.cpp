// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer
// ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum
// equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise,
// return false.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursion Optimised : Memoization
public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(arr, dp, k, n - 1);
    }

    bool solve(vector<int> &arr, vector<vector<int>> &dp, int k, int n)
    {
        if (n == 0 || k == 0)
        {
            if (k == 0)
                return true;
            else
                return (arr[n] == k);
        }

        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }

        // pick element
        bool pick = false;
        if (k >= arr[n])
        {
            pick = solve(arr, dp, k - arr[n], n - 1);
        }

        if (pick)
        {
            return pick;
        }

        // No pick
        bool notPick = solve(arr, dp, k, n - 1);

        return dp[n][k] = pick || notPick;
    }
};

class Solution1
{
    // Recursion Optimised
public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        return solve(arr, k, n - 1);
    }

    bool solve(vector<int> &arr, int k, int n)
    {
        if (n == 0 || k == 0)
        {
            if (k == 0)
                return true;
            else
                return (arr[n] == k);
        }

        // pick element
        bool pick = false;
        if (k >= arr[n])
        {
            pick = solve(arr, k - arr[n], n - 1);
        }

        if (pick)
        {
            return pick;
        }

        // No pick
        bool notPick = solve(arr, k, n - 1);

        return pick || notPick;
    }
};

class Solution
{
    // Simple recursive solution
public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        return solve(arr, k, n - 1);
    }

    bool solve(vector<int> &arr, int &k, int n)
    {
        if (n < 0 || k <= 0)
        {
            if (k == 0)
            {
                return true;
            }
            return false;
        }

        // pick element
        k -= arr[n];
        if (solve(arr, k, n - 1))
        {
            return true;
        }

        // No pick
        k += arr[n];
        if (solve(arr, k, n - 1))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 88;

    Solution1 Obj1;
    cout << Obj1.subsetSumToK(4, k, arr);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}