//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int Maximize(int a[], int n)
    {
        const unsigned int M = 1000000007;
        sort(a, a + n);
        unsigned long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = (((i % M) * (a[i] % M)) % M + sum) % M;
        }
        return sum;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.Maximize(a, n) << endl;
    }
}
// } Driver Code Ends