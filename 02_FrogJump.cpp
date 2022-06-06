// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// There is a frog on the 1st step of an N stairs long staircase.
// The frog wants to reach the Nth stair. HEIGHT[i] is the height
// of the (i+1)th stair.If Frog jumps from ith to jth stair, the
// energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
// In the Frog is on ith staircase, he can jump either to (i+1)th
// stair or to (i+2)th stair. Your task is to find the minimum total
// energy used by the frog to reach from 1st stair to Nth stair.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Simple Recursion - Wrong answer 
public:
    int frogJump(int n, vector<int> &heights)
    {
        int ans = INT_MAX, energy = 0;
        solve(n - 1, heights, ans, energy);
        return ans;
    }
    void solve(int n, vector<int> &heights, int &ans, int &energy)
    {
        if (n < 1)
        {
            if (n == 0)
            {
                ans = min(ans, energy);
            }
            return;
        }
        // Take one step
        energy += abs(heights[n] - heights[n - 1]);
        solve(n - 1, heights, ans, energy);
        energy -= abs(heights[n] - heights[n - 1]);
        // Take two step
        if (n > 1)
        {
            energy += abs(heights[n] - heights[n - 2]);
            solve(n - 2, heights, ans, energy);
        }
        else
        {
            return;
        }
    }
};

int main()
{
    vector<int> heights = {10, 20, 30, 10};
    Solution Obj1;
    cout << Obj1.frogJump(4, heights);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}