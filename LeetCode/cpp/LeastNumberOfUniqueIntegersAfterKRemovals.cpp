class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> counter;

        for (int &num : arr)
        {
            counter[num] += 1;
        }

        vector<vector<int>> vcounter;
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            vcounter.push_back({it->first, it->second});
        }

        // the smaller count, the earlier be popped
        auto comp = [](const vector<int> &p, const vector<int> &q)
        {
            return p[1] > q[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(vcounter.begin(), vcounter.end(), comp);

        while (!pq.empty() && k > 0)
        {
            vector<int> p = pq.top();
            pq.pop();
            if (k < p[1])
            {
                pq.push({p[0], p[1] - k});
            }
            k -= p[1];
        }

        return pq.size();
    }
};

// More Speed
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> cnt;
        for (const int &x : arr)
        {
            ++cnt[x];
        }
        vector<int> nums;
        for (const auto &[_, c] : cnt)
        {
            nums.push_back(c);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0, m = nums.size(); i < m; ++i)
        {
            k -= nums[i];
            if (k < 0)
            {
                return m - i;
            }
        }
        return 0;
    }
};

/*
Explanation:
1. Count the frequency of each number.
2. Store the frequency of each number in a vector.
3. Sort the vector.
4. Subtract the frequency of each number from k.
5. If k becomes negative, return the number of unique integers left.
6. If k becomes zero, return 0.
7. If k is still positive, return 0.
*/

// More Speed
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> cnt;
        for (const int &x : arr)
        {
            ++cnt[x];
        }

        // Min-heap to store frequencies
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto &[_, c] : cnt)
        {
            minHeap.push(c);
        }

        // Remove elements with the smallest frequencies
        while (!minHeap.empty() && k > 0)
        {
            k -= minHeap.top();
            if (k >= 0)
            {
                minHeap.pop();
            }
        }

        // The remaining elements in the heap are the unique elements left
        return minHeap.size();
    }
};