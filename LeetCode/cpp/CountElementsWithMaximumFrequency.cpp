class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        int max = 0;
        int result = 0;
        for (auto it : nums)
        {
            umap[it]++;
            if (umap[it] > max)
                max = umap[it];
        }
        for (auto &it : umap)
        {
            if (max == it.second)
                result += it.second;
        }
        return result;
    }
};