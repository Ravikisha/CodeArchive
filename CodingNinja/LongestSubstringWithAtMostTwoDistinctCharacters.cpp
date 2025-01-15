// Time Complexity: O(n)
// Space Complexity: O(1)
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int l = 0, result = INT_MIN;
    unordered_map<char, int> umap;
    for (int r = 0; r < n; r++)
    {
        umap[s[r]]++;
        while (umap.size() > 2)
        {
            umap[s[l]]--;
            if (umap[s[l]] == 0)
                umap.erase(s[l]);
            l++;
        }
        result = max(result, r - l + 1);
    }
    return result;
}
