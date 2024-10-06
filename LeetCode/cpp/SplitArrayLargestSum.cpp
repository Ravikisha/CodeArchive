class Solution
{
    // Time Complexity: O(log(n))
    // Space Complexity: O(1)
public:
    int allocateSubArray(const vector<int> &arr, int block)
    {
        int k = 1;
        long long subArraySum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (subArraySum + arr[i] <= block)
            {
                subArraySum += arr[i];
            }
            else
            {
                k++;
                subArraySum = arr[i];
            }
        }
        return k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
            return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (allocateSubArray(nums, mid) > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};