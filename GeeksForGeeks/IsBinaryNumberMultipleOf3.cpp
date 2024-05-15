//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int isDivisible(string s)
    {
        int even = 0;
        int odd = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int x = (s[i] - '0');
            if ((i % 2) == 0)
                even = even + x;
            else
                odd = odd + x;
        }
        int res = even - odd;
        if ((res % 3) == 0)
            return 1;
        else
            return 0;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
    return 0;
}

// } Driver Code Ends