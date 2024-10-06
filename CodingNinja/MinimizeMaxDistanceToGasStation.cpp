// Better Solution
// Time Complexity: O(n*log(n) + k*log(n))
// Space Complexity: O(n-1)

#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }
    for (int gasStation = 1; gasStation <= k; gasStation++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}
/*
Explaination:
1. Create a howMany array of size n-1 and initialize it with 0.
2. Create a priority queue of pair<long double, int> and push the difference of adjacent elements in the array.
3. For each gas station, pop the top element from the priority queue and increment the howMany array at the index of the second element of the pair.
4. Calculate the new length of the segment and push it back to the priority queue.
5. Return the top element of the priority queue.

Example:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.5

Iteration 1:
gasStation = 1
    pq = [(1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7), (1, 8)]
    tp = (1, 8)
    secInd = 8
    howMany = [0, 0, 0, 0, 0, 0, 0, 0, 1]
    iniDiff = 1
    newSecLen = 0.5
    pq = [(0.5, 8), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7)]

Iteration 2:
gasStation = 2
    pq = [(0.5, 8), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7)]
    tp = (1, 7)
    secInd = 7
    howMany = [0, 0, 0, 0, 0, 0, 0, 1, 1]
    iniDiff = 1
    newSecLen = 0.5
    pq = [(0.5, 7), (0.5, 8), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6)]

Iteration 3:
gasStation = 3
    pq = [(0.5, 7), (0.5, 8), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6)]
    tp = (1, 6)
    secInd = 6
    howMany = [0, 0, 0, 0, 0, 0, 1, 1, 1]
    iniDiff = 1
    newSecLen = 0.5
    pq = [(0.5, 6), (0.5, 7), (0.5, 8), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5)]

Simalarly, we can calculate for other gas stations.
Iteration Final:
gasStation = 9
    pq = [(0.5, 0), (0.5, 1), (0.5, 2), (0.5, 3), (0.5, 4), (0.5, 5), (0.5, 6), (0.5, 7), (0.5, 8)]
    tp = (0.5, 8)
    secInd = 8
    howMany = [1, 1, 1, 1, 1, 1, 1, 1, 1]
    iniDiff = 1
    newSecLen = 0.5
    pq = [(0.5, 0), (0.5, 1), (0.5, 2), (0.5, 3), (0.5, 4), (0.5, 5), (0.5, 6), (0.5, 7), (0.5, 8)]

Return 0.5


*/

// Optimized Solution
// Time Complexity: O(n*log(n) + log(n))
// Space Complexity: O(1)
#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    auto countOfGasStationsRequired = [=](long double dist)
    {
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;
            if ((arr[i] - arr[i - 1]) / dist == numberInBetween * dist)
            {
                numberInBetween--;
            }
            count += numberInBetween;
        }
        return count;
    };
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = low + (high - low) / 2.0;
        int count = countOfGasStationsRequired(mid);
        if (count > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}
