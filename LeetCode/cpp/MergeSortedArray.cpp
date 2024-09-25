class Solution
{
    // Time: O(n), Space: O(1)
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m + n - 1; // nums1 last index

        // merge from the end
        while (m > 0 && n > 0)
        {
            // if nums1 last element is greater than nums2 last element
            if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[i] = nums1[m - 1];
                m--;
            }
            // if nums2 last element is greater than nums1 last element
            else
            {
                nums1[i] = nums2[n - 1];
                n--;
            }
            i--;
        }
        // if nums2 has remaining elements
        while (n > 0)
        {
            nums1[i] = nums2[n - 1];
            n--;
            i--;
        }
    }
};