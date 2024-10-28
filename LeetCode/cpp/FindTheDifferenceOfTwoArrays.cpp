class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> count; // To count occurrences of elements
        vector<vector<int>> ans(2);

        // Count elements in nums1
        for (int num : nums1)
        {
            count[num] |= 1; // Mark as present in nums1
        }

        // Count elements in nums2
        for (int num : nums2)
        {
            count[num] |= 2; // Mark as present in nums2
        }

        // Collect results
        for (const auto &[num, presence] : count)
        {
            if (presence == 1)
            { // Present only in nums1
                ans[0].push_back(num);
            }
            else if (presence == 2)
            { // Present only in nums2
                ans[1].push_back(num);
            }
        }

        return ans;
    }
};