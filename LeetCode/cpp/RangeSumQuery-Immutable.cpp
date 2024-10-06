// Using Prefix Sum Technique with Hash Map
class NumArray
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    unordered_map<int, int> umap;
    NumArray(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            umap[i] = sum;
        }
    }

    int sumRange(int left, int right)
    {
        return umap[right] - (left == 0 ? 0 : umap[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Using Prefix Sum Technique with Vector
class NumArray
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> prefixSum;
    NumArray(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefixSum.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        return prefixSum[right] - (left == 0 ? 0 : prefixSum[left - 1]);
    }
};