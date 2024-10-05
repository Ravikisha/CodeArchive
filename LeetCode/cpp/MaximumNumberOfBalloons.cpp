class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> m;
        for (char &c : text)
        {
            m[c]++;
        }
        return min({m['b'], m['a'], m['l'] / 2, m['o'] / 2, m['n']});
    }
};