class Solution
{
    // Time Complexity: O(n+m)
    // Space Complexity: O(k) where k is the number of unique words and pattern characters.
public:
    vector<string> split(string str)
    {
        vector<string> res;
        int length = int(str.length());
        int index = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                res.push_back(str.substr(index, i - index));
                index = i + 1;
            }
        }
        res.push_back(str.substr(index));
        return res;
    }
    bool wordPattern(string pattern, string s)
    {
        vector<string> words = split(s);
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (charToWord.find(pattern[i]) != charToWord.end() &&
                charToWord[pattern[i]] != words[i])
                return false;
            if (wordToChar.find(words[i]) != wordToChar.end() &&
                wordToChar[words[i]] != pattern[i])
                return false;
            charToWord[pattern[i]] = words[i];
            wordToChar[words[i]] = pattern[i];
        }
        return true;
    }
};