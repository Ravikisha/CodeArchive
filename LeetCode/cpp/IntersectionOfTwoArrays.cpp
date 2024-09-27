// Optimal Solution
class Solution
{
    // Time Complexity: O(n + m)
    // Space Complexity: O(m)
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> uset;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            uset.insert(nums1[i]);
        }
        for (int j = 0; j < nums2.size(); j++)
        {
            if (uset.find(nums2[j]) != uset.end())
            {
                result.push_back(nums2[j]);
                uset.erase(nums2[j]);
            }
        }
        return result;
    }
};

// Two Pointer Solution
class Solution {
    // Time Complexity: O(nlogn + mlogm)
    // Space Complexity: O(1)
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // Avoid duplicates in the result
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};
