class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        int pos = -1;

        // find nums[i] and nums[i+1] s.t. nums[i] > nums[i+1]
        for (int i = 0; i + 1 < n; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                if (pos == -1)
                {
                    pos = i;
                }
                else
                {
                    // if we find 2 or more such i, then it's impossible
                    return false;
                }
            }
        }

        /*
        pos == -1: no such i, so it's definitely possible
        pos == 0 or pos+1 == n-1, the two elements are at the edge,
        can make it good by setting nums[pos+1] = nums[pos]

        otherwise, pos-1, pos, pos+1, pos+2 all exist,
        we can
        (1) change nums[pos] to nums[pos-1],
        e.g. [1,3,2,4], pos = 1, change it to [1,1,2,4]
        or
        (2) change nums[pos+1] to nums[pos],
        e.g. [1,2,4,3], pos = 1, change to to [1,2,2,3]

        fail case:
        e.g. [4,6,2,3], pos = 1, since 4>2 and 6>3,
        we cannot just change one element
        */

        return (pos == -1) || (pos == 0) || (pos + 1 == n - 1) || (nums[pos - 1] <= nums[pos + 1]) || (nums[pos] <= nums[pos + 2]);
    }
};