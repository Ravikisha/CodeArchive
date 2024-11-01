class Solution
{
    // Time Complexity: O(n * m) where n is the number of words and m is the average length of the words
    // Space Complexity: O(n)
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> indices;
        for (int i = 0; i < order.size(); i++)
        {
            indices[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            string w1 = words[i], w2 = words[i + 1];
            for (int j = 0; j < w1.size(); j++)
            {
                if (j == w2.size())
                    return false;
                if (w1[j] != w2[j])
                {
                    if (indices[w2[j]] < indices[w1[j]])
                        return false;
                    break;
                }
            }
        }
        return true;
    }
};