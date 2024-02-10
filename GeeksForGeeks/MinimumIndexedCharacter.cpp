//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_map<char, int> um;

        int minIndex = INT_MAX;

        int m = str.size();
        int n = patt.size();

        for (int i = 0; i < m; i++)
        {
            if (um.find(str[i]) == um.end())
                um[str[i]] = i;
        }
        for (int j = 0; j < n; j++)
        {
            if (um.find(patt[j]) != um.end() && um[patt[j]] < minIndex)
                minIndex = um[patt[j]];
        }

        if (minIndex == INT_MAX)
            return -1;
        return minIndex;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        string patt;
        cin >> str;
        cin >> patt;
        Solution obj;
        cout << obj.minIndexChar(str, patt) << endl;
    }
    return 0;
}

// } Driver Code Ends