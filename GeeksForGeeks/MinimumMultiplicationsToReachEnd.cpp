//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // Time Complexity: O(100000)
    // Space Complexity: O(100000)
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q;
        q.push({start, 0});
        dist[start] = 0;
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int node = curr.first;
            int steps = curr.second;
            if (node == end)
                return steps;
            for (auto it : arr)
            {
                int value = (node * it) % 100000;
                if (steps + 1 < dist[value])
                {
                    dist[value] = steps + 1;
                    q.push({value, steps + 1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;

        cout << "~" << "\n";
    }
}

// } Driver Code Ends