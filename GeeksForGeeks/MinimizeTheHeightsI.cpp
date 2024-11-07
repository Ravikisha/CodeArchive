//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    int getMinDiff(int k, vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return 0; // Only one tower, no difference to minimize

        sort(arr.begin(), arr.end());

        int minDiff = arr[n - 1] - arr[0]; // Initial difference between max and min

        // Check possible new heights
        for (int i = 0; i < n - 1; i++)
        {
            int new_min = min(arr[0] + k, arr[i + 1] - k);
            int new_max = max(arr[i] + k, arr[n - 1] - k);
            minDiff = min(minDiff, new_max - new_min);
        }

        return minDiff;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;

    cin >> t;
    cin.ignore();

    while (t--)
    {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends