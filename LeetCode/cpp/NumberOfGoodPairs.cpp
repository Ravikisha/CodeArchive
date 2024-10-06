class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int pairCount = 0;
        unordered_map<int, int> umap;
        for (int num : nums)
        {
            pairCount += (umap.find(num) != umap.end() ? umap[num] : 0);
            umap[num]++;
        }
        return pairCount;
    }
};