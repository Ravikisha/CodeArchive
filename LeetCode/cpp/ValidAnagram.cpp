// better solution
class Solution
{
    // Time Complexity: O(nlogn + mlogm) where n is the length of s and m is the length of t
    // Space Complexity: O(1)
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Optimal Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }
        return true;
    }
};
