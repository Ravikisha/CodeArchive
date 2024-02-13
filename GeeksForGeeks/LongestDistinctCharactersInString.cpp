//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars(string S);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        cout << longestSubstrDistinctChars(S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

int longestSubstrDistinctChars(string S)
{
    unordered_set<char> set;
    int start = 0, end = 0;
    int len = INT_MIN;

    while (start < S.size() && end < S.size())
    {
        if (set.find(S[end]) == set.end())
        {
            set.insert(S[end++]);
            len = max(len, end - start);
        }
        else
        {
            set.erase(S[start++]);
        }
    }
    return len;
}