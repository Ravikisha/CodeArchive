class Solution
{
    // Time Complexity: O(n + klogn)
    // Space Complexity: O(n + k)
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> triples;
        for (auto &p : points)
            triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
        vector<vector<int>> res;
        while (k--)
        {
            vector<int> el = pq.top();
            pq.pop();
            res.push_back({el[1], el[2]});
        }
        return res;
    }
};