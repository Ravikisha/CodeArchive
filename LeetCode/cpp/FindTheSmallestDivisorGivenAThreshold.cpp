class Solution
{
    // Time Complexity: O(n*log(m))
    // Space Complexity: O(1)
public:
    bool valid(vector<int> &nums, int threshold, int divisor)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / (double)divisor);

            if (sum > threshold)
            {
                return false;
            }
        }

        return true;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (valid(nums, threshold, mid))
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