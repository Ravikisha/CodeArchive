//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int firstZero(int arr[], int low, int high)
    {
        if (high >= low)
        {
            // Check if mid element is first 0
            int mid = low + (high - low) / 2;
            if ((mid == 0 || arr[mid - 1] == 1) && arr[mid] == 0)
                return mid;

            if (arr[mid] == 1) // If mid element is not 0
                return firstZero(arr, (mid + 1), high);
            else // If mid element is 0, but not first 0
                return firstZero(arr, low, (mid - 1));
        }
        return -1;
    }
    int countZeroes(int arr[], int n)
    {
        // Find index of first zero in given array
        int first = firstZero(arr, 0, n - 1);

        // If 0 is not present at all, return 0
        if (first == -1)
            return 0;

        return (n - first);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends