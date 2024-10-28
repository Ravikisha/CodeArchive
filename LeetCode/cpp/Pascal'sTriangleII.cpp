class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        long c = 1;
        for (int i = 0; i <= rowIndex; i++)
        {
            result.push_back(c);
            c = c * (rowIndex - i) / (i + 1);
        }
        return result;
    }
};