//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
public:
    string removeUtil(string &s)
    {
        int n = s.size();
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && s[i] == s[i + 1])
            {
                while (i < n - 1 && s[i] == s[i + 1])
                    i++;
            }
            else
            {
                s[k++] = s[i];
            }
        }
        s.erase(k);
        if (k != n)
            removeUtil(s);
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution ob;
        s = ob.removeUtil(s);
        if (s.size() == 0)
            cout << "\"\"";
        else
            cout << s << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends