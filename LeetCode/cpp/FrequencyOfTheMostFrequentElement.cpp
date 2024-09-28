class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int maxFreq = 0;
        long long total = 0;
        int left = 0, right = 0;
        while (right < nums.size())
        {
            total += nums[right];
            while ((long long)nums[right] * (long long)(right - left + 1) > (long long)total + k)
            {
                total -= nums[left++];
            }
            maxFreq = max(maxFreq, right - left + 1);
            right++;
        }
        return maxFreq;
    }
};

/*
Explaination:
1. Sort the array.
2. Use two pointers left and right to maintain a window.
3. Calculate the total sum of the window.
4. If the window is not valid, then increment the left pointer.
5. Update the maxFreq.
6. Return the maxFreq.

Formula:
total + k >= (long long)nums[right] * (long long)(right - left + 1)
*/