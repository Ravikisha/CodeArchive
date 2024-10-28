class Solution
{
    // Time Complexity: O(N * 4^L) where N is the number of cells in the board and L is the length of the word
    // Space Complexity: O(L) where L is the length of the word
public:
    bool splitString(string s)
    {
        int n = s.size();

        // Recursive backtracking function to check if we can split the string
        function<bool(int, long long)> backtrack = [&](int index, long long prev)
        {
            // Base case: if we've reached the end of the string with valid splits
            if (index == n)
                return true;

            // Try to split the string into increasing substrings starting from `index`
            for (int i = index; i < n; i++)
            {
                // Convert substring to long long; handle potential overflow
                string substring = s.substr(index, i - index + 1);
                long long val;

                try
                {
                    val = stoll(substring); // Convert substring to long long
                }
                catch (...)
                {
                    break; // Exit loop if overflow occurs
                }

                // Check if the current value is exactly 1 less than the previous value
                if (val + 1 == prev && backtrack(i + 1, val))
                    return true;
            }
            return false; // If no valid split found, return false
        };

        // Try to split starting from different initial segments
        for (int i = 0; i < n - 1; i++)
        {
            // Convert the initial substring to long long
            string initialSubstring = s.substr(0, i + 1);
            long long initialValue;

            try
            {
                initialValue = stoll(initialSubstring); // Convert initial segment to long long
            }
            catch (...)
            {
                break; // Exit loop if overflow occurs
            }

            // Start backtracking from the next index with the initial value
            if (backtrack(i + 1, initialValue))
                return true;
        }

        // Return false if no valid decreasing sequence is found
        return false;
    }
};