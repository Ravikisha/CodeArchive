class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxi = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        long long cnt = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            if (nums[j] == maxi)
                cnt++;

            while (cnt >= k)
            {
                ans += n - j;
                if (nums[i] == maxi)
                    cnt--;

                i++;
            }
            j++;
        }
        return ans;
    }
};