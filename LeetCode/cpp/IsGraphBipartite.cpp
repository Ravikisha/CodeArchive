class Solution
{
    // Time Complexity: O(V + E)
    // Space Complexity: O(V)
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> colored(v, -1); // -1 means no color assigned
        queue<int> q;

        for (int i = 0; i < v; i++)
        { // Start BFS for every unvisited node
            if (colored[i] == -1)
            {
                q.push(i);
                colored[i] = 0; // Start coloring with 0
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for (int neighbor : graph[curr])
                    {
                        // If the neighbor has the same color as the current node, it's not bipartite
                        if (colored[neighbor] == colored[curr])
                        {
                            return false;
                        }
                        // If the neighbor hasn't been colored, color it with the opposite color and push it to the queue
                        if (colored[neighbor] == -1)
                        {
                            colored[neighbor] = colored[curr] ^ 1; // Flip the color
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return true;
    }
};