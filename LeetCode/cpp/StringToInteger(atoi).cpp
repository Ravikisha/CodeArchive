class Solution
{
public:
    int myAtoi(string s)
    {
        // Check if string is empty.
        if (s.empty())
        {
            return 0;
        }

        int ans = 0;
        int sign = 1;
        int i = 0;

        // Skip whitespace.
        while (s[i] == ' ' || s[i] == '\t')
        {
            ++i;
        }
        // Check if string is empty after skipping whitespace.
        if (i == s.length())
        {
            return 0;
        }

        // Parse sign.
        if (s[i] == '+')
        {
            ++i;
        }
        else if (s[i] == '-')
        {
            sign = -1;
            ++i;
        }

        // Compute integer.
        for (; i < s.length() && isdigit(s[i]); ++i)
        {
            if (ans > (numeric_limits<int>::max() - (s[i] - '0')) / 10)
            {
                return sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            ans *= 10;
            ans += s[i] - '0';
        }

        ans *= sign;
        return ans;
    }
};