// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

// Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their
// union is the original array. Let the sum of the elements of these two subsets be ‘S1’
// and ‘S2’.
// Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or
// equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the
// answer may be too large, return it modulo ‘10^9 + 7’.
// If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2
// are considered different if:

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Tabulation 
    int mod = (int)(1e9 + 7);

public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totalSum = 0;
        for (int &a : arr)
            totalSum += a;
        int target = (totalSum - d) / 2;
        if ((totalSum - d) % 2 != 0 || (totalSum - d) < 0)
            return 0;

                
    }
};

class Solution1
{
    // Memoization : Recursion
    int mod = (int)(1e9 + 7);

public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totalSum = 0;
        for (int &a : arr)
            totalSum += a;
        int target = (totalSum - d) / 2;
        if ((totalSum - d) % 2 != 0 || (totalSum - d) < 0)
            return 0;
        // solve(n, arr, target, ans);
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve (n-1, target, arr, dp) ;
    }
    int solve(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (sum == 0 || num[0] == 0)
                return 2;
            if (sum == 0 || sum == num[0])
                return 1;
            return 0;
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int notTake = solve(ind - 1, sum, num, dp);
        int take = 0;
        if (num[ind] <= sum)
            take = solve(ind - 1, sum - num[ind], num, dp);

        return dp[ind][sum] = (notTake + take) % mod;
    }
};

class Solution
{
    // Brute Force : Recursion
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totalSum = 0;
        for (int &a : arr)
            totalSum += a;
        int target = (totalSum - d) / 2, ans = 0;
        if ((totalSum - d) % 2 != 0 || (totalSum - d) < 0)
            return 0;
        solve(n, arr, target, ans);
        return ans;
    }
    void solve(int n, vector<int> &arr, int target, int ans, int i = 0)
    {
        // Your code goes here
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}