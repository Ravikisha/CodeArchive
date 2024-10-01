class Solution
{
    // Time Complexity: O(nlogk)
    // Space Complexity: O(k)
public:
    bool check(const string &s, const string &p, const vector<int> &removable, int x)
    {
        unordered_set<int> lookup;
        for (int i = 0; i < x; ++i)
        {
            lookup.emplace(removable[i]);
        }
        int j = 0;
        for (int i = 0; i < size(s); ++i)
        {
            if (lookup.count(i) || s[i] != p[j])
            {
                continue;
            }
            if (++j == size(p))
            {
                return true;
            }
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int l = 0, r = removable.size();
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (!check(s, p, removable, m))
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return r;
    }
};