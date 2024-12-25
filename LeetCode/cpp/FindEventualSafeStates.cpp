class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V+E)
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<vector<int>> revAdj(v);
        vector<int> inDegree(v, 0);

        // Reverse the graph
        for (int i = 0; i < v; i++)
        {
            for (auto it : graph[i])
            {
                revAdj[it].push_back(i);
                inDegree[i]++;
            }
        }

        // Topological sort
        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < v; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : revAdj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};