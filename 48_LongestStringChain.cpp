// https://leetcode.com/problems/longest-string-chain/

// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(const string &s1, const string &s2)
    {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for (string w : words)
        {
            for (int i = 0; i < w.length(); i++)
            {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};

class Solution
{
    // TLE: Time Limit Exceeded
public:
    bool compare(string s, string t)
    {
        if (s.size() - t.size() != 1)
            return false;
        int i = 0, j = 0, flag = 1;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
                ++i, ++j;
            else
            {
                if (flag)
                    ++i, flag = 0;
                else
                    return false;
            }
        }
        return true;
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string s, string t)
             { return s.length() > t.length(); });
        int n = words.size();
        // dp[i] signifies the size of subsequece if ss ends at index i
        vector<int> dp(n, 1);
        int maxIndex = 0, maxVal = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (compare(words[i], words[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    if (maxVal < dp[i])
                    {
                        maxVal = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}