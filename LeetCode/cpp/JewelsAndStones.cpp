class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> umap;
        int count = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            umap[stones[i]]++;
        }
        for (int i = 0; i < jewels.size(); i++)
        {
            if (umap.find(jewels[i]) != umap.end())
            {
                count += umap[jewels[i]];
            }
        }
        return count;
    }
};

// Using HashSet

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int count = 0;
        for (char stone : stones)
        {
            if (jewelSet.find(stone) != jewelSet.end())
            {
                count++;
            }
        }
        return count;
    }
};