// Better Solution
class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
public:
    int lengthOfLongestSubstring(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            int temp = 0;
            int arr[256] = {0};
            while (j < s.size() && arr[s[j]] == 0)
            {
                arr[s[j]] = 1;
                temp++;
                j++;
            }
            if (temp > count)
            {
                count = temp;
            }
        }
        return count;
    }
};

// Optimal Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n) // To store the last index of each character
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndex; // To store the last index of each character
        int maxLength = 0, start = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (charIndex.find(s[i]) != charIndex.end() && charIndex[s[i]] >= start)
            {
                // If the character is already in the map and is in the current window
                start = charIndex[s[i]] + 1; // Move the start pointer after the duplicate
            }
            charIndex[s[i]] = i;                       // Update the index of the current character
            maxLength = max(maxLength, i - start + 1); // Update the maximum length
        }

        return maxLength;
    }
};
/*
Explaination:
1. We will use a hash map to store the last index of each character.
2. We will use two pointers, start and i, to keep track of the current window.
3. If the character is already in the map and is in the current window, we will move the start pointer after the duplicate.
4. We will update the index of the current character in the map.
5. We will update the maximum length.
6. Finally, we will return the maximum length.
*/

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1) // Since the set will have at most 26 characters
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> uset;
        int l = 0, len = 0, n = s.size();
        for (int r = 0; r < n; r++)
        {
            while (uset.find(s[r]) != uset.end())
            {
                uset.erase(s[l]);
                l++;
            }
            uset.insert(s[r]);
            len = max(len, r - l + 1);
        }
        return len;
    }
};