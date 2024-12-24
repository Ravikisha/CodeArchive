class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> e(n + 1);
        for (auto &p : edges)
        {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        function<int(int, int)> dfs = [&](int curr, int parent)
        {
            int time = 0;
            for (int child : e[curr])
            {
                if (child == parent)
                    continue;
                int childTime = dfs(child, curr);
                if (childTime > 0 || hasApple[child])
                {
                    time += 2 + childTime;
                }
            }
            return time;
        };
        return dfs(0, -1);
    }
};