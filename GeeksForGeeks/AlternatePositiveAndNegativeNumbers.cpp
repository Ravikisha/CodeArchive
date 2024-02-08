//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }
        int k = 0, l = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0 and k < pos.size())
                arr[i] = pos[k++];
            else if (1 % 2 != 0 and l < neg.size())
                arr[i] = neg[l++];
            else if (k == pos.size() and l < neg.size())
                arr[i] = neg[l++];
            else
                arr[i] = pos[k++];
        }
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends