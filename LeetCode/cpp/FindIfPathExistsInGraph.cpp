class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> adj;
        for (const auto &edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        return dfs(adj, source, destination);
    }

private:
    int dfs(const unordered_map<int, vector<int>> &adj,
            const int start,
            const int target)
    {
        vector<int> stk = {start};
        unordered_set<int> lookup;
        while (!empty(stk))
        {
            auto pos = stk.back();
            stk.pop_back();
            if (pos == target)
            {
                return true;
            }
            if (!adj.count(pos))
            {
                continue;
            }
            for (const auto &nei : adj.at(pos))
            {
                if (lookup.count(nei))
                {
                    continue;
                }
                lookup.emplace(nei);
                stk.emplace_back(nei);
            }
        }
        return false;
    }
};