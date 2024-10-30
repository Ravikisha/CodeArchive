class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool isVowel(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
            x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s)
    {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j)
        { // Fix: Use i < j instead of i < n && j >= 0
            while (i < j && !isVowel(s[i]))
                i++; // Ensure i < j in inner loops
            while (i < j && !isVowel(s[j]))
                j--; // Ensure i < j in inner loops
            if (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};