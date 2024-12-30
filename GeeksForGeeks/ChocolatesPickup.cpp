//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time complexity: O(n * m^2)
    // Space complexity: O(n * m^2)
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // Initialize the last row
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                {
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                }
                else
                {
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }

        // Fill the dp table for all rows above the last one
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = -1e8;

                    // Try all possible moves for both robots
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;

                            // If both robots are in the same column, only one collects chocolates
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }

                            // Check the bounds for both robots' new positions
                            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            }
                            else
                            {
                                value += -1e8; // Invalid moves, penalize
                            }

                            maxi = max(maxi, value);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        // The answer is the maximum chocolates collected starting at (0, 0) and (0, m-1)
        return dp[0][0][m - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends