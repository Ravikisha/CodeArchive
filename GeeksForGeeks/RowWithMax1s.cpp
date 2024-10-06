//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
    // Time Complexity: O(n*log(m))
    // Space Complexity: O(1)
public:
    int lowerBound(const vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int result = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        int maxIndex = -1;
        int maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            int countOnes = m - lowerBound(arr[i], m, 1);
            if (maxCount < countOnes)
            {
                maxCount = countOnes;
                maxIndex = i;
            }
        }
        return maxIndex;
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
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends