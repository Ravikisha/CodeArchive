class Solution
{
    // Time Complexity: O(n*26*wordLength)
    // Space Complexity: O(n)
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty())
        {
            pair<string, int> cur = q.front();
            q.pop();
            int size = cur.first.size();
            for (int i = 0; i < size; i++)
            {
                string word = cur.first;
                for (int j = 0; j < 26; j++)
                {
                    word[i] = 'a' + j;
                    if (word == endWord)
                        return cur.second + 1;
                    if (words.find(word) != words.end())
                    {
                        q.push({word, cur.second + 1});
                        words.erase(word);
                    }
                }
            }
        }
        return 0;
    }
};