class TimeMap
{
    // Time Complexity: O(logn)
    // Space Complexity: O(n)
public:
    unordered_map<string, vector<pair<string, int>>> umap;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        umap[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        if (umap.find(key) == umap.end())
        {
            return "";
        }
        const vector<pair<string, int>> &values = umap[key];
        int l = 0, r = values.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (values[mid].second < timestamp)
            {
                // res = values[mid].first;
                l = mid + 1;
            }
            else if (values[mid].second > timestamp)
            {
                r = mid - 1;
            }
            else
            {
                return values[mid].first;
            }
        }
        return (r >= 0) ? values[r].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */