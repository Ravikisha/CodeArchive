class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    string largestGoodInteger(string num)
    {
        string result;
        int n = num.size();

        for (int i = 0; i < n - 2; i++)
        { // Adjusted loop to go till n-2
            // Check for three consecutive identical digits
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                string temp = num.substr(i, 3); // Take exactly three characters
                // Compare the found triplet with the current result
                if (temp > result)
                {
                    result = temp; // Update result if it's larger
                }
                // Move index to skip this triplet
                i += 2; // Move forward to avoid re-checking
            }
        }
        return result;
    }
};