class Solution
{
    // Time Complexity: O(n * 2^n)
    // Space Complexity: O(n)
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end)
    {
        // Check characters from the outside in
        while (start <= end)
        {
            // If characters don't match, it's not a palindrome
            if (s[start] != s[end])
                return false;
            start++; // Move start pointer to the right
            end--;   // Move end pointer to the left
        }
        return true; // If all characters matched, it is a palindrome
    }

    // Main function to partition the string into all palindrome substrings
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result; // Result vector to store all partitions
        vector<string> part;           // Temporary vector to store current partition
        int n = s.size();              // Length of the input string

        // Backtracking function to find partitions starting from a given index
        function<void(int)> backtrack = [&](int index)
        {
            // If index reaches the end, add current partition to result
            if (index == n)
            {
                result.push_back(part);
                return;
            }

            // Try to partition the string from the current index to each possible endpoint
            for (int i = index; i < n; i++)
            {
                // Check if the substring from index to i is a palindrome
                if (isPalindrome(s, index, i))
                {
                    part.push_back(s.substr(index, i - index + 1)); // Add substring to the current partition
                    backtrack(i + 1);                               // Recurse to the next part
                    part.pop_back();                                // Backtrack and remove the last added substring
                }
            }
        };

        backtrack(0);  // Start backtracking from the first character
        return result; // Return all valid palindrome partitions
    }
};
