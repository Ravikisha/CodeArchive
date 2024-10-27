class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int cur = 0;
        for (int x = 0; x <= n; ++x)
        {
            while (cur < n && nums[cur] < x)
            {
                ++cur;
            }

            if (n - cur == x)
                return x;
        }

        return -1;
    }
};

// optimized solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> count(n + 1, 0);

        // Count the number of elements for each possible value
        for (int num : nums)
        {
            if (num >= n)
            {
                count[n]++;
            }
            else
            {
                count[num]++;
            }
        }

        // Accumulate counts from the end to calculate elements >= x
        for (int i = n - 1; i >= 0; --i)
        {
            count[i] += count[i + 1];
        }

        // Check for the special integer
        for (int x = 0; x <= n; ++x)
        {
            if (count[x] == x)
            {
                return x;
            }
        }

        return -1;
    }
};