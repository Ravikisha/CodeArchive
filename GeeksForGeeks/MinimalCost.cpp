//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n*k)
    // Space Complexity: O(n)
    // Bottom Up Approach
public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int minStep = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                    minStep = min(minStep, jump);
                }
            }
            dp[i] = minStep;
        }
        return dp[n - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends