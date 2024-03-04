//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int MOD = 1000000007;
class Solution
{
public:
    int sumOfNaturals(int n)
    {
        long long sum = (long long)n * (n + 1) / 2;
        return sum % MOD;
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

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends