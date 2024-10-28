class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(26) or O(1)
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> freq(26, 0);
        for (auto ch : chars)
        {
            int index = ch - 'a';
            freq[index]++;
        }

        int count = 0;
        for (auto str : words)
        {
            vector<int> temp = freq;
            int i;
            for (i = 0; str[i] != '\0'; i++)
            {
                int index = str[i] - 'a';
                if (temp[index] == 0)
                    break;
                temp[index]--;
            }
            if (str[i] == '\0')
                count += i;
        }

        return count;
    }
};