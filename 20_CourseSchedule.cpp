// https://leetcode.com/problems/course-schedule-iii/

// There are n different online courses numbered from 1 to n. You
// are given an array courses where courses[i] = [durationi, lastDayi]
// indicate that the ith course should be taken continuously for durationi
// days and must be finished before or on lastDayi.

// You will start on the 1st day and you cannot take two or more
// courses simultaneously.

// Return the maximum number of courses that you can take.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        priority_queue<int> pq;
        int total = 0;
        for (auto &course : courses)
        {
            int dur = course[0], end = course[1];
            if (dur + total <= end)
                total += dur, pq.push(dur);
            else if (pq.size() && pq.top() > dur)
                total += dur - pq.top(), pq.pop(), pq.push(dur);
        }
        return pq.size();
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}