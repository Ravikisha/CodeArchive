//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> nthRowOfPascalTriangle(int n)
    {
        vector<int> result;
        int c = 1;
        for (int i = 1; i <= n; i++)
        {
            result.push_back(c);
            c = c * (n - i) / i;
        }
        return result;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends