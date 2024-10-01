class Solution
{
    // Time Complexity: O(nlogn + n * m)
    // Space Complexity: O(n)
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        int n = products.size();
        int searchLength = searchWord.size();
        vector<vector<string>> result;

        // Sort the products lexicographically
        sort(products.begin(), products.end());

        // Initialize the left and right pointers
        int l = 0, r = n - 1;

        // Iterate over each character of the searchWord
        for (int i = 0; i < searchLength; i++)
        {
            char c = searchWord[i];

            // Move the left pointer to skip products that don't match the prefix
            while (l <= r && (products[l].size() <= i || products[l][i] != c))
            {
                l++;
            }

            // Move the right pointer to skip products that don't match the prefix
            while (l <= r && (products[r].size() <= i || products[r][i] != c))
            {
                r--;
            }

            // Add up to 3 matching products to the result
            vector<string> temp;
            for (int j = l; j < min(l + 3, r + 1); j++)
            {
                temp.push_back(products[j]);
            }
            result.push_back(temp);
        }

        return result;
    }
};