class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> count;
        int sum = 0, result = 0;

        for (int num : nums)
        {
            count[sum]++;
            sum += num;
            result += count[sum - goal];
        }

        return result;
    }
};