//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(N + P)
    // Space Complexity: O(N)
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> adj(N);
        for (auto it : prerequisites)
        {
            adj[it.first].push_back(it.second);
        }

        vector<int> inDegree(N, 0);
        // InDegree Table
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        int count = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for (auto it : adj[curr])
            {
                // Remove the indegree point from the curr node
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        if (count == N)
            return true;
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends