class Solution
{
    // Time Complexity: O(log(n))
    // Space Complexity: O(1)
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return k + high + 1;
    }
};

/*
Explanation:
1. Initialize low = 0 and high = n - 1.
2. Iterate while low <= high.
3. Calculate mid = low + (high - low) / 2.
4. Calculate missing = arr[mid] - (mid + 1). This will give the number of missing elements before the mid element.
5. If missing < k, then set low = mid + 1.
6. Else, set high = mid - 1.
7. Return k + high + 1.

Example:
arr = [2, 3, 4, 7, 11], k = 5
low = 0, high = 4
mid = 2, missing = 4 - (2 + 1) = 1
missing < k, so low = 3
low = 3, high = 4
mid = 3, missing = 7 - (3 + 1) = 3
missing >= k, so high = 2
low = 3, high = 2
Return 5 + 2 + 1 = 8
*/