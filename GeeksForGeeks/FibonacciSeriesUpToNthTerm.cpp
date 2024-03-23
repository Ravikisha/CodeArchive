//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> Series(int n)
    {
        const unsigned int M = 1000000007;
        vector<int> f(n + 1);
        int i;

        f[0] = 0;
        f[1] = 1;

        for (i = 2; i <= n; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]) % M;
        }
        return f;
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
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends