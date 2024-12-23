class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(26) = O(1)
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> firstIndex(26, -1); // Stores the first occurrence of each character
        int maxLength = -1;

        for (int i = 0; i < s.size(); i++)
        {
            int charIndex = s[i] - 'a';
            if (firstIndex[charIndex] == -1)
            {
                // Record the first occurrence of the character
                firstIndex[charIndex] = i;
            }
            else
            {
                // Calculate the length of the substring between this and the first occurrence
                maxLength = max(maxLength, i - firstIndex[charIndex] - 1);
            }
        }

        return maxLength;
    }
};