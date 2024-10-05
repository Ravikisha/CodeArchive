class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> umap;
        for (char c : magazine)
        {
            umap[c]++;
        }
        for (char c : ransomNote)
        {
            if (umap[c] <= 0)
                return false;
            umap[c]--;
        }
        return true;
    }
};