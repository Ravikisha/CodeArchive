class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    string destCity(vector<vector<string>> &paths)
    {
        string destination = paths[0][1];
        unordered_map<string, string> umap;
        for (vector<string> path : paths)
        {
            umap[path[0]] = path[1];
        }
        // while (umap.find(destination) != umap.end())
        // {
        //     destination = umap[destination];
        // }
        for(const auto& [s,d]: umap){
            if(umap.count(d) == 0){
                destination = d;
                break;
            }
        }

        return destination;
    }
};