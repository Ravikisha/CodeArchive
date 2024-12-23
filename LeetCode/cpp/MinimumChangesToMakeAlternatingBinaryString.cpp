class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int minOperations(string s)
    {
        int n = s.size();
        int changesToPattern0 = 0; // Count changes to match "0101..."
        int changesToPattern1 = 0; // Count changes to match "1010..."

        for (int i = 0; i < n; i++)
        {
            // Pattern 0: index % 2 == 0 -> '0', index % 2 == 1 -> '1'
            if (i % 2 == 0)
            {
                if (s[i] != '0')
                    changesToPattern0++;
                if (s[i] != '1')
                    changesToPattern1++;
            }
            // Pattern 1: index % 2 == 0 -> '1', index % 2 == 1 -> '0'
            else
            {
                if (s[i] != '1')
                    changesToPattern0++;
                if (s[i] != '0')
                    changesToPattern1++;
            }
        }

        // Return the minimum changes required
        return min(changesToPattern0, changesToPattern1);
    }
};