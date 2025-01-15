//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // Time Complexity: O(n^3)
    // Space Complexity: O(n^2)
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        int dp[n][n];
        for (int i = 1; i < n; i++)
            dp[i][i] = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                int mini = 1e9;
                for (int k = i; k < j; k++)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--)
    {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl
             << "~\n";
    }

    return 0;
}

// } Driver Code Ends