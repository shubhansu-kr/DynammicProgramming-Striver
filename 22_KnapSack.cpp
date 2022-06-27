// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

// A thief is robbing a store and can carry a maximal weight of W into his
// knapsack. There are N items and the ith item weighs wi and is of value vi.
// Considering the constraints of the maximum weight that a knapsack can carry,
// you have to find and return the maximum value that a thief can generate by stealing items.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursion : Memoization 
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

    Solution Obj1;
    cout << Obj1.knapsack(weight, value, n, maxWeight);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}