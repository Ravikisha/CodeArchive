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
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<int> dp(capacity + 1, 0);
        for (int W = 0; W <= capacity; W++)
        {
            dp[W] = ((int)(W / wt[0])) * val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int W = 0; W <= capacity; W++)
            {
                int notTake = dp[W];
                int take = 0;
                if (wt[i] <= W)
                    take = val[i] + dp[W - wt[i]];
                dp[W] = max(take, notTake);
            }
        }
        return dp[capacity];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num)
        {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2)
        {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends