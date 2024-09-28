class Solution
{
    // Time Complexity: O(n*m) where n is the length of biggest word and m is the length of strs array
    // Space Complexity: O(1)
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            // i: index of char
            for (int j = 1; j < strs.size(); j++)
            {
                // j: index of str
                if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};