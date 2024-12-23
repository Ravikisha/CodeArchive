class Solution
{
    // Time Complexity: O(n*m) where m is the average length of the strings
    // Space Complexity: O(26) = O(1)
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        vector<int> charCount(26, 0);
        for (string word : words)
        {
            for (char c : word)
            {
                charCount[c - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (charCount[i] % n != 0)
                return false;
        }
        return true;
    }
};