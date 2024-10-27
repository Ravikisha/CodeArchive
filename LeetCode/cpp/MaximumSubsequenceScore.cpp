bool sortDescending(const pair<int, int> &lhs,
                    const pair<int, int> &rhs)
{
    return lhs.second > rhs.second;
}
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> pairs;
        pairs.reserve(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            pairs.push_back(make_pair(nums1[i], nums2[i]));
        }
        sort(pairs.begin(), pairs.end(), sortDescending);
        long long result = INT_MIN;
        long long n1Sum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (pair<int, int> nums : pairs)
        {
            n1Sum += nums.first;
            minHeap.push(nums.first);
            if (minHeap.size() > k)
            {
                n1Sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k)
            {
                result = max(result, n1Sum * nums.second);
            }
        }
        return result;
    }
};