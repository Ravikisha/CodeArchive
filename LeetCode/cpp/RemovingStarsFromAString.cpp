class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    string removeStars(string s)
    {
        string ans;
        for (char c : s)
        {
            if (c == '*')
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};