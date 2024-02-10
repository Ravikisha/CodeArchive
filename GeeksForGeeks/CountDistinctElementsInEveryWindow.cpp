//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        unordered_map<int, int> umap;
        vector<int> results;
        int dist = 0;

        for (int i = 0; i < k; i++)
        {
            if (umap[A[i]] == 0)
            {
                dist++;
            }
            umap[A[i]] += 1;
        }
        results.push_back(dist);

        for (int i = k; i < n; i++)
        {
            if (umap[A[i - k]] == 1)
            {
                dist--;
            }
            umap[A[i - k]] -= 1;

            if (umap[A[i]] == 0)
            {
                dist++;
            }
            umap[A[i]] += 1;
            results.push_back(dist);
        }
        return results;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends