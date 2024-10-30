class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int largestAltitude(vector<int> &gain)
    {
        int result = 0;
        int sum = 0;
        for (int num : gain)
        {
            sum += num;
            result = max(result, sum);
        }
        return result;
    }
};