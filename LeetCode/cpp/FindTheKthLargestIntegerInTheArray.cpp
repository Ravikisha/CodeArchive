class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    string kthLargestNumber(vector<string> &nums, int k)
    {
        auto cmp = [](const string &a, const string &b)
        { return a.size() == b.size() ? a > b : a.size() > b.size(); };
        sort(nums.begin(), nums.end(), cmp);
        return nums[k - 1];
    }
};
// Optimal Solution using Priority Queue
class Solution
{
    // Time Complexity: O(nlogk)
    // Space Complexity: O(k)
public:
    string kthLargestNumber(vector<string> &nums, int k)
    {
        auto cmp = [](const string &a, const string &b)
        { return a.size() == b.size() ? a > b : a.size() > b.size(); };
        priority_queue<string, vector<string>, decltype(cmp)> minHeap(cmp);

        // Add first k elements to the min-heap
        for (int i = 0; i < nums.size(); i++)
        {
            if (minHeap.size() < k)
            {
                minHeap.push(nums[i]);
            }
            else if (cmp(nums[i], minHeap.top()))
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};