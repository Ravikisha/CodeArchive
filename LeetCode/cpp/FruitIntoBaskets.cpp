class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_map<int, int> umap;
        int left = 0, total = 0, result = 0;
        for (int r = 0; r < n; r++)
        {
            umap[fruits[r]]++;
            total++;
            while (umap.size() > 2)
            {
                umap[fruits[left]]--;
                total--;
                if (umap[fruits[left]] == 0)
                {
                    umap.erase(fruits[left]);
                }
                left++;
            }
            result = max(result, total);
        }
        return result;
    }
};