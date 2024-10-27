// Better Solution
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int num : nums)
            pq.push(num);
        for (int i = 0; i < k - 1 && !pq.empty(); i++)
            pq.pop();
        return pq.top();
    }
};

// Optimal Solution
class Solution
{
    // Time Complexity: O(nlogk)
    // Space Complexity: O(k)
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};