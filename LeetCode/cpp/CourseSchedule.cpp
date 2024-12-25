class Solution
{
    // Time Complexity: O(N + P)
    // Space Complexity: O(N)
public:
    bool canFinish(int N, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(N);
        for (auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
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