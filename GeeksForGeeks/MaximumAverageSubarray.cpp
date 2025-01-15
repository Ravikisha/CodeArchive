//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int findMaxAverage(int arr[], int n, int k)
    {
        int maxi = INT_MIN;
        int sum = 0;
        int startingIndex = 0;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        maxi = sum;
        for (int i = k; i < n; i++)
        {
            sum += arr[i];
            sum -= arr[i - k];
            if (sum > maxi)
            {
                startingIndex = i - k + 1;
                maxi = sum;
            }
        }
        return startingIndex;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends