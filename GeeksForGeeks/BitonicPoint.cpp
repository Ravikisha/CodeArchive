//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int findMax(int *arr, int low, int high)
    {
        // If there is only one element
        if (low == high)
        {
            return arr[low];
        }

        // If there are two elements and the first is greater than the second
        if (high == low + 1 && arr[low] >= arr[high])
        {
            return arr[low];
        }

        // If there are two elements and the second is greater than the first
        if (high == low + 1 && arr[low] < arr[high])
        {
            return arr[high];
        }

        // Find the middle element
        int mid = (low + high) / 2;

        // If the middle element is the maximum element
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return arr[mid];
        }

        // If the middle element is not the maximum element
        if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        {
            return findMax(arr, low, mid - 1);
        }
        else
        {
            return findMax(arr, mid + 1, high);
        }

        return -1;
    }

    int findMaximum(int arr[], int n)
    {
        return findMax(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends