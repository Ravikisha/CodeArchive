class Solution
{
    // Time Complexity: O(nlog(sum(weights)))
    // Space Complexity: O(1)
public:
    int findDays(vector<int> &weights, int cap)
    {
        int days = 1, load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] + load > cap)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int numberOfDays = findDays(weights, mid);
            if (numberOfDays <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
/*
Explanation:
1. Find the minimum capacity of the ship to carry all the packages.
2. Find the maximum capacity of the ship to carry all the packages.
3. Apply binary search between the minimum and maximum capacity.
4. Find the number of days required to carry all the packages with the mid capacity.
5. If the number of days is less than or equal to the given days, then search in the left half.
6. If the number of days is greater than the given days, then search in the right half.
7. Return the low value.
*/