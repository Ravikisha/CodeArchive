// General Solution (Fastest)
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans;
        for (int i = 0; i < nums.size(); ++i)
            ans += nums[i][i] == '0' ? '1' : '0';
        return ans;
    }
};

// Backtrack Solution
class Solution
{
    // Time Complexity: O(2^n)
    // Space Complexity: O(2^n)
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end()); // Convert nums to a set for fast lookup
        string result;

        // Backtracking function to generate all binary strings of length `n`
        function<bool(string &, int)> backtrack = [&](string &current, int length)
        {
            // Base case: if we've generated a binary string of length `n`
            if (length == n)
            {
                if (numSet.find(current) == numSet.end())
                { // If current string is not in nums
                    result = current;
                    return true; // Found a missing string, so we can stop
                }
                return false;
            }

            // Recursive case: try adding '0' and '1' to the current binary string
            current.push_back('0'); // Try '0' at this position
            if (backtrack(current, length + 1))
                return true;
            current.pop_back(); // Undo adding '0'

            current.push_back('1'); // Try '1' at this position
            if (backtrack(current, length + 1))
                return true;
            current.pop_back(); // Undo adding '1'

            return false;
        };

        string current;
        backtrack(current, 0); // Start backtracking with an empty string
        return result;
    }
};