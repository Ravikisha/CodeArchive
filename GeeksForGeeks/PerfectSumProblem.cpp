//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n*target)
    // Space Complexity: O(target)
public:
    int perfectSum(vector<int> &arr, int target)
    {
        const int MOD = 1e9 + 7; // To avoid overflow, use modulo operation.
        int n = arr.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // There is always one subset (empty subset) with a sum of 0.

        // Initialize the first element.
        if (arr[0] <= target)
            dp[arr[0]] += 1;

        for (int i = 1; i < n; i++)
        {
            for (int tar = target; tar >= 0; tar--)
            {
                if (arr[i] <= tar)
                {
                    dp[tar] = (dp[tar] + dp[tar - arr[i]]) % MOD;
                }
            }
        }

        return dp[target];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--)
    {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value)
        {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends