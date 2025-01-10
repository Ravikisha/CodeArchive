//{ Driver Code Starts
// Initial template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    pair<int, int> get(int a, int b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return {a, b};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        Solution ob;
        pair<int, int> p = ob.get(a, b);
        cout << p.first << ' ' << p.second << endl;

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends