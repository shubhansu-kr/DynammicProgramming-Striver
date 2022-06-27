// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

// A thief is robbing a store and can carry a maximal weight of W into his
// knapsack. There are N items and the ith item weighs wi and is of value vi.
// Considering the constraints of the maximum weight that a knapsack can carry,
// you have to find and return the maximum value that a thief can generate by stealing items.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation: Space Optimised
public:
    int knapsack(vector<int> &weight, vector<int> &value, int &n, int &maxWeight)
    {
        // Write your code here
        vector<int> cp(maxWeight+1);
        for (int i = 0; i <= maxWeight; ++i)
        {
            if(weight[0] <= i) cp[i]= value[0];
        }
        for (int i = 1; i < n; ++i)
        {
            vector<int> temp(maxWeight+1);
            for (int j = 0; j <= maxWeight; ++j)
            {
                int pick = INT_MIN;
                if (weight[i] <= j)
                {
                    pick = value[i] + cp[j-weight[i]];
                }
                // NotPick
                int noPick = cp[j];
                temp[j] = max(pick, noPick) ;
            }
            cp = temp ;
        }
        return cp[maxWeight];
    }
};

class Solution2
{
    // Tabulation
public:
    int knapsack(vector<int> &weight, vector<int> &value, int &n, int &maxWeight)
    {
        // Write your code here
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1));

        for (int i = 0; i <= maxWeight; ++i)
        {
            if(weight[0] <= i) dp[0][i] = value[0];
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= maxWeight; ++j)
            {
                int pick = INT_MIN;
                if (weight[i] <= j)
                {
                    pick = value[i] + dp[i-1][j-weight[i]];
                }
                // NotPick
                int noPick = dp[i-1][j];
                dp[i][j] = max(pick, noPick) ;
            }
        }
        return dp[n-1][maxWeight];
    }
};

class Solution1
{
    // Recursion : Memoization
public:
    int knapsack(vector<int> &weight, vector<int> &value, int &n, int &maxWeight)
    {
        // Write your code here
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
        return steal(weight, value, dp, maxWeight);
    }

    int steal(vector<int> &weight, vector<int> &value, vector<vector<int>> &dp, int maxWeight, int i = 0)
    {
        if (i == weight.size())
        {
            return 0;
        }

        if (dp[i][maxWeight] != -1)
            return dp[i][maxWeight];

        // Pick
        int pick = INT_MIN;
        if (weight[i] <= maxWeight)
        {
            pick = value[i] + steal(weight, value, dp, maxWeight - weight[i], i + 1);
        }
        // NotPick
        int noPick = steal(weight, value, dp, maxWeight, i + 1);

        return dp[i][maxWeight] = max(pick, noPick);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int knapsack(vector<int> &weight, vector<int> &value, int &n, int &maxWeight)
    {
        // Write your code here
        return steal(weight, value, maxWeight);
    }

    int steal(vector<int> &weight, vector<int> &value, int maxWeight, int i = 0)
    {
        if (i == weight.size())
        {
            return 0;
        }

        // Pick
        int pick = INT_MIN;
        if (weight[i] <= maxWeight)
        {
            pick = value[i] + steal(weight, value, maxWeight - weight[i], i + 1);
        }
        // NotPick
        int noPick = steal(weight, value, maxWeight, i + 1);

        return max(pick, noPick);
    }
};

int main()
{
    int n = 4, maxWeight = 5;
    vector<int> weight = {1, 2, 4, 5}, value = {5, 4, 8, 6};

    Solution3 Obj1;
    cout << Obj1.knapsack(weight, value, n, maxWeight);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}