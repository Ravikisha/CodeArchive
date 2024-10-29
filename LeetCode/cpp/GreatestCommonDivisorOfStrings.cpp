class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int greastestCommonDivisor(int x, int y)
    {
        return y == 0 ? x : greastestCommonDivisor(y, x % y);
    }
    string gcdOfStrings(string str1, string str2)
    {
        int l1 = str1.size(), l2 = str2.size();
        int gcd = greastestCommonDivisor(l1, l2);
        string sgcd = str1.substr(0, gcd);
        for (int i = 0; i < l1 / gcd; i++)
        {
            if (str1.substr(i * gcd, gcd) != sgcd)
                return "";
        }

        for (int i = 0; i < l2 / gcd; i++)
        {
            if (str2.substr(i * gcd, gcd) != sgcd)
                return "";
        }

        return sgcd;
    }
};