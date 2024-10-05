class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int num : nums)
        {
            int numCount = 0;
            while (num > 0)
            {
                numCount++;
                num /= 10;
            }
            if (numCount % 2 == 0)
                count++;
        }
        return count;
    }
};