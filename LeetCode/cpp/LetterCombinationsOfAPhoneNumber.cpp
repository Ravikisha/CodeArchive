class Solution
{
    // Time Complexity: O(4^n)
    // Space Complexity: O(n)
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        unordered_map<char, string> digitToChar;
        digitToChar['2'] = "abc";
        digitToChar['3'] = "def";
        digitToChar['4'] = "ghi";
        digitToChar['5'] = "jkl";
        digitToChar['6'] = "mno";
        digitToChar['7'] = "qprs";
        digitToChar['8'] = "tuv";
        digitToChar['9'] = "wxyz";

        function<void(int, string)> backtrack = [&](int i, string currStr)
        {
            if (currStr.size() == digits.size())
            {
                result.push_back(currStr);
                return;
            }
            for (char c : digitToChar[digits[i]])
            {
                backtrack(i + 1, currStr + c);
            }
        };
        if (!digits.empty())
            backtrack(0, "");
        return result;
    }
};