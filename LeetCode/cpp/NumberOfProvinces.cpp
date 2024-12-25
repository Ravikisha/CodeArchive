class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity : O(n)
public:
    void dfs(int node, vector<vector<int>> &adjLs, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!visited[it])
            {
                dfs(it, adjLs, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();
        vector<vector<int>> adjLs(v); // Adjacency list

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                }
            }
        }

        vector<int> visited(v, 0); // Use a vector to track visited nodes
        int count = 0;

        // Perform DFS for each component
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, adjLs, visited);
            }
        }

        return count;
    }
};