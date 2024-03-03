//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

int findElement(int arr[], int n)
{
    int Left[n];
    int Right[n];
    Left[0] = INT_MIN;
    Right[n - 1] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        Left[i] = max(arr[i - 1], Left[i - 1]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        Right[i - 1] = min(Right[i], arr[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= Left[i] && arr[i] <= Right[i])
        {
            return arr[i];
        }
    }
    return -1;
}