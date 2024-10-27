class valuecomparator
{
public:
    valuecomparator() {}
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const
    {
        return lhs.second > rhs.second;
    }
};
class Solution
{
    // Time Complexity: O(nlogk)
    // Space Complexity: O(n)
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> counter;
        vector<int> ans(k);

        for (int e : nums)
        {
            counter[e]++;
        }

        // the larger the lower
        priority_queue<pair<int, int>, vector<pair<int, int>>, valuecomparator> pq1;

        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            pq1.push(*it);
            // the smallest will be popped first
            if (pq1.size() > k)
                pq1.pop();
        }

        // put into ans in reverse order
        for (int i = k - 1; i >= 0; i--)
        {
            pair<int, int> p = pq1.top();
            ans[i] = p.first;
            pq1.pop();
        }

        return ans;
    }
};

// using sorting to avoid the map data structure
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> freqs;
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (nums[left] != nums[right])
            {
                freqs.push({right - left, nums[left]});
                left = right;
            }
            right++;
        }
        freqs.push({right - left, nums[left]});
        vector<int> res;
        while (k > 0)
        {
            res.push_back(freqs.top().second);
            freqs.pop();
            k--;
        }
        return res;
    }
};