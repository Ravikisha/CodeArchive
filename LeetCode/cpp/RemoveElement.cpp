class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0; // Points to the position to overwrite
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};