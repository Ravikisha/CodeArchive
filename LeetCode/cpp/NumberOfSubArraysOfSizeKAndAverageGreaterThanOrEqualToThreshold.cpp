class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        threshold *= k;
        int ans = 0;
        for (int i = 0, s = 0; i < arr.size(); ++i)
        {
            s += arr[i];
            if (i >= k)
                s -= arr[i - k];
            if (i >= k - 1 && s >= threshold)
                ++ans;
        }
        return ans;
    }
};