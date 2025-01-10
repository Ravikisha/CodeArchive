//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    bool isEven(int n)
    {
        return n & 1 == 1 ? false : true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        if (ob.isEven(N))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends