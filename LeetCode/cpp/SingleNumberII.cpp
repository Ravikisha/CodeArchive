class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int bit = 0; bit < 32; bit++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] & (1 << bit))
                    count++;
            }
            if (count % 3 == 1)
            {
                ans |= (1 << bit);
            }
        }
        return ans;
    }
};

class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 3)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[n - 1];
    }
};

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};