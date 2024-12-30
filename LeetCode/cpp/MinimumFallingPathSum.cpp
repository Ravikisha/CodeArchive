class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    // Tabulation (Bottom-Up Dynamic Programming) with Space Optimization
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> dp(n, 0);

        // Initialize dp with the first row of the matrix
        for (int j = 0; j < n; j++)
        {
            dp[j] = matrix[0][j];
        }

        // Traverse from the second row to the last row
        for (int i = 1; i < n; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                // Falling from directly above
                int above = dp[j];

                // Falling from the left diagonal
                int left = (j > 0) ? dp[j - 1] : INT_MAX;

                // Falling from the right diagonal
                int right = (j < n - 1) ? dp[j + 1] : INT_MAX;

                // Minimum of all possible falling paths to this cell
                temp[j] = matrix[i][j] + min(above, min(left, right));
            }
            dp = temp; // Update dp for the next row
        }

        // The result is the minimum value in the last row
        return *min_element(dp.begin(), dp.end());
    }
};