class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V+E)
public:
    vector<int> findOrder(int v, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(v);
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]); // Reverse edge: course dependency
        }

        vector<int> inDegree(v, 0);
        // Build in-degree table
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        // Push all nodes with in-degree 0
        for (int i = 0; i < v; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> result;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for (auto it : adj[curr])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        // If result size is less than the number of nodes, there is a cycle
        if (result.size() != v)
            return {};

        return result;
    }
};