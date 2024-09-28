// Unoptimize Solution
class Solution
{
    // Time Complexity: O((m -n +1) nlogn)
    // Space Complexity: O(1)
public:
    bool checkAnagram(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        int low = 0;
        for (int i = n - 1; i < m; i++)
        {
            string part = s2.substr(low, n);
            if (checkAnagram(s1, part))
            {
                return true;
            }
            else
            {
                low++;
            }
        }
        return false;
    }
};

// Optimized Solution
class Solution
{
    // Time Complexity: O(m)
    // Space Complexity: O(1)
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        // if the length of s1 is greater than s2, then return false
        if (n > m)
            return false;
        // create two arrays to store the count of each character in s1 and s2
        int s1Count[26] = {0};
        int s2Count[26] = {0};
        // count the number of matches between s1 and s2
        int matches = 0;
        // count the number of characters in s1 and s2
        for (int i = 0; i < n; i++)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        // count the number of matches between s1 and s2
        for (int i = 0; i < 26; i++)
        {
            if (s1Count[i] == s2Count[i])
                matches++;
        }
        // if all the characters in s1 are present in s2, then return true
        int left = 0;
        for (int r = n; r < m; r++)
        {
            // if all the characters in s1 are present in s2, then return true
            if (matches == 26)
                return true;
            
            int index = s2[r] - 'a';
            // increment the count of the character in s2
            s2Count[index]++;
            // if the count of the character in s1 and s2 are equal, then increment the matches
            if (s1Count[index] == s2Count[index])
                matches++;
            // if the count of the character in s1 is greater than the count of the character in s2, then decrement the matches
            else if (s1Count[index] + 1 == s2Count[index])
                matches--;
            // decrement the count of the character in s2
            index = s2[left] - 'a';
            s2Count[index]--;
            // if the count of the character in s1 and s2 are equal, then increment the matches
            if (s1Count[index] == s2Count[index])
                matches++;
            // if the count of the character in s1 is less than the count of the character in s2, then decrement the matches
            else if (s1Count[index] - 1 == s2Count[index])
                matches--;
            left++;
        }
        return matches == 26;
    }
};