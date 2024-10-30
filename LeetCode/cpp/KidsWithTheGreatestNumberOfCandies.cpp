class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxChoc = *max_element(candies.begin(), candies.end()); // Find max candies
        vector<bool> result;
        result.reserve(candies.size()); // Reserve space for efficiency

        for (int candy : candies)
        {
            result.push_back(candy + extraCandies >= maxChoc); // Directly push result
        }

        return result;
    }
};
