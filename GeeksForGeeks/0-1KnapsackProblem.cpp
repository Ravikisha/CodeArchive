//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n*capacity)
    // Space Complexity: O(capacity)
public:
    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<int> dp(capacity + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            for (int j = capacity; j >= wt[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        }

        return dp[capacity];
    }
};

//{ Driver Code Starts.

int main()
{
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--)
    {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends