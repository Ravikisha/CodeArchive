class DSU
{
public:
    vector<int> parent, rank, size;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1); // Initialize size correctly
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // Initialize each node as its own parent
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
    // Time Complexity: O(N^2)
    // Space Complexity: O(N^2)
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DSU ds(n * n);

        // Union all connected `1`s
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int index = 0; index < 4; index++)
                {
                    int newr = row + dr[index];
                    int newc = col + dc[index];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Check if grid has any zero
        bool hasZero = false;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                {
                    hasZero = true;
                    break;
                }
            }
            if (hasZero)
                break;
        }

        // If the grid is entirely 1s
        if (!hasZero)
            return n * n;

        // Calculate maximum size after flipping a `0`
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;

                for (int index = 0; index < 4; index++)
                {
                    int newr = row + dr[index];
                    int newc = col + dc[index];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n)
                    {
                        if (grid[newr][newc] == 1)
                        {
                            components.insert(ds.find(newr * n + newc));
                        }
                    }
                }

                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        return mx;
    }
};
