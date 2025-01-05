//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n * m)
    // Space Complexity: O(min(n, m))
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<int> dp(m + 1, 0);
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            int prev = 0; // Store dp[j - 1] from the previous row
            for (int j = 1; j <= m; j++)
            {
                int temp = dp[j]; // Temporarily store the current dp[j] before
                                  // updating
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[j] = 1 + prev; // Use prev instead of dp[j - 1]
                    count = max(count, dp[j]);
                }
                else
                    dp[j] = 0;
                prev = temp; // Update prev for the next iteration
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends