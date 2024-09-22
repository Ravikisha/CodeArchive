class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string res = "";

        for (int i = 0; i < numRows; i++)
        {
            int incr = 2 * (numRows - 1);
            for (int j = i; j < s.size(); j += incr)
            {
                res += s[j];
                if (i > 0 && i < numRows - 1 && j + incr - 2 * i < s.size())
                {
                    res += s[j + incr - 2 * i];
                }
            }
        }
        return res;
    }
};