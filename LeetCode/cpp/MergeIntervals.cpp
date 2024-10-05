class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end());
        int i = 1;
        while (i < intervals.size())
        {
            if (intervals[i - 1][1] >= intervals[i][0])
            {
                // merge them
                intervals[i - 1][1] = max(intervals[i - 1][1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
            }
            else
            {
                i++;
            }
        }

        return intervals;
    }
};

/*
Explaination:
1. Sort the intervals based on the start time.
2. Iterate through the intervals and merge them if they overlap.
3. If they don't overlap, move to the next interval.
4. Return the merged intervals.
*/

// Optimal Solution
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;

        // sort by start point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (vector<int> &interval : intervals)
        {
            if (ans.empty() || ans.back()[1] < interval[0])
            {
                ans.push_back(interval);
            }
            else
            {
                ans[ans.size() - 1][1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};

/*
Explaination:
1. Sort the intervals based on the start time.
2. If the current interval's start time is greater than the previous interval's end time, then add the current interval to the answer.
3. Otherwise, merge the current interval with the previous interval.
4. Return the merged intervals.
*/