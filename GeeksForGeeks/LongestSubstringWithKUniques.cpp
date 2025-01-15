//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(k)
public:
    int longestKSubstr(string &s, int k)
    {
        int result = INT_MIN;
        unordered_map<char, int> umap;
        int n = s.size();
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            umap[s[r]]++;
            while (umap.size() > k)
            {
                umap[s[l]]--;
                if (umap[s[l]] == 0)
                {
                    umap.erase(s[l]);
                }
                l++;
            }
            if (umap.size() == k)
                result = max(result, r - l + 1);
        }
        return result == INT_MIN ? -1 : result;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends