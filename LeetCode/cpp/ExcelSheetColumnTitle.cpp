class Solution
{
    // Time Complexity: O(log_26(columnNumber))
    // Space Complexity: O(log_26(columnNumber))
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";

        while (columnNumber > 0)
        {
            columnNumber--; // Adjust for zero-indexed 'A'
            int remainder = columnNumber % 26;
            result = char(remainder + 'A') + result;
            columnNumber /= 26;
        }

        return result;
    }
};