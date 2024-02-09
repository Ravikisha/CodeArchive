//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxOnes(vector<vector<int>> &Mat, int N, int M)
    {
        int ans = INT_MIN;
        int result;
        for (int i = 0; i < N; i++)
        {
            int count = 0;
            for (int j = 0; j < M; j++)
            {
                if (Mat[i][j] == 1)
                {
                    count++;
                }
            }
            if (ans < count)
            {
                ans = count;
                result = i;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends