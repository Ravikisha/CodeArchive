// Optimal Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int i = 0, j = 1;
        int n = nums.size();

        vector<int> ans(n);

        for (int p = 0; p < n; p++)
        {
            if (nums[p] < 0)
            {
                ans[j] = nums[p];
                j += 2;
            }
            else
            {
                ans[i] = nums[p];
                i += 2;
            }
        }

        return ans;
    }
};

// Another Approach
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> neg, pos;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        if (pos.size() > neg.size())
        {
            for (int i = 0; i < neg.size(); i++)
            {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for (int i = neg.size(); i < pos.size(); i++)
            {
                nums[index++] = pos[i];
            }
        }
        else
        {
            for (int i = 0; i < pos.size(); i++)
            {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }
            int index = pos.size() * 2;
            for (int i = pos.size(); i < neg.size(); i++)
            {
                nums[index++] = neg[i];
            }
        }
        return nums;
    }
};

// More Optimal Approach But not Accepted by LeetCode
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        int pos = 0, neg = 1;
        while (neg < n && pos < n)
        {
            while (pos < n && nums[pos] > 0)
            {
                pos += 2;
            }
            while (neg < n && nums[neg] < 0)
            {
                neg += 2;
            }

            // swap the values
            if (pos < n && neg < n)
            {
                swap(nums[pos], nums[neg]);
            }
        }
        return nums;
    }
};

// Same Solution but accepted by LeetCode by different way
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        std::stable_partition(nums.begin(), nums.end(), [](auto num)
                              { return num >= 0; });
        const int middle = nums.size() / 2;
        for (int idx = 1; idx < nums.size(); ++idx)
        {
            const bool shouldBePositive = idx % 2 == 0;
            const bool positive = nums[idx] >= 0;
            if (shouldBePositive == positive)
            {
                continue;
            }
            int idxSwap = idx;
            int valSaved = nums[idxSwap];
            do
            {
                idxSwap = idxSwap >= middle ? 2 * (idxSwap - middle) + 1 : 2 * idxSwap;
                swap(valSaved, nums[idxSwap]);
            } while (idxSwap != idx);
        }
        return std::move(nums);
    }
};