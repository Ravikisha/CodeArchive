class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool checkVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k)
    {
        int n = s.size();
        int count = 0;
        int left = 0;
        int result = 0;
        for (int r = 0; r < n; r++)
        {
            if (checkVowel(s[r]))
                count++;
            if (r - left + 1 > k)
            {
                if (checkVowel(s[left]))
                    count--;
                left++;
            }
            result = max(result, count);
        }
        return result;
    }
};