// Better Solution
class Solution
{
    // Time Complexity: O(m+n)
    // Space Complexity: O(m+n)
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        int size = size1 + size2;
        int i = 0, j = 0, k = 0;
        int *nums = new int[size];
        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
            {
                nums[k++] = nums1[i++];
            }
            else
            {
                nums[k++] = nums2[j++];
            }
        }
        while (i < size1)
        {
            nums[k++] = nums1[i++];
        }
        while (j < size2)
        {
            nums[k++] = nums2[j++];
        }
        double res;
        if (size % 2 == 0)
        {
            res = (nums[size / 2] + nums[size / 2 - 1]) / 2.0;
        }
        else
        {
            res = nums[size / 2];
        }
        delete[] nums;
        return res;
    }
};

// Optimal Solution
class Solution {
    // Time Complexity: O(log(min(m, n)))
    // Space Complexity: O(1)
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            } else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};
