//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // Time Complexity: O(n*capacity)
    // Space Complexity: O(capacity)
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> dp(n + 1, 0);
        for (int N = 0; N <= n; N++)
        {
            dp[N] = N * price[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int N = 0; N <= n; N++)
            {
                int notTake = dp[N];
                int take = INT_MIN;
                int rodLength = i + 1;
                if (rodLength <= N)
                    take = price[i] + dp[N - rodLength];
                dp[N] = max(take, notTake);
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends