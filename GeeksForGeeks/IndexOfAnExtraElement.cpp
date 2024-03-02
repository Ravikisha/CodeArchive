//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findExtra(int a[], int b[], int n)
    {
        int i = 0, j = n - 1;

        while (i <= j)
        {
            int m = (i + j) / 2;
            if (m == n)
                return m;
            else if (a[m] == b[m])
                i = m + 1;
            else if (a[m] != b[m])
                j = m - 1;
        }
        return i;
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
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}
// } Driver Code Ends