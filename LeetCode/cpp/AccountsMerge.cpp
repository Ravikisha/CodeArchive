class DSU
{
public:
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
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

    void unionSet(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX != parentY)
        {
            if (rank[parentX] > rank[parentY])
            {
                parent[parentY] = parentX;
            }
            else if (rank[parentX] < rank[parentY])
            {
                parent[parentX] = parentY;
            }
            else
            {
                parent[parentY] = parentX;
                rank[parentX]++;
            }
        }
    }
};
class Solution
{
    // Time complexity: O(ElogE)
    // Space complexity: O(V)
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    ds.unionSet(i, mapMailNode[mail]);
                }
            }
        }
        vector<vector<string>> mergeMail(n);
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.find(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergeMail[i].size() != 0)
            {
                sort(mergeMail[i].begin(), mergeMail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                temp.insert(temp.end(), mergeMail[i].begin(), mergeMail[i].end());
                ans.push_back(temp);
            }
        }
        return ans;
    }
};