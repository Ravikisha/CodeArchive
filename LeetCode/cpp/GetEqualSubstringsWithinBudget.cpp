class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = abs(s[i] - t[i]);
        int ans = 0;
        for (int l = 0, r = 0, x = 0; r < n; ++r)
        {
            x += a[r];
            while (x > maxCost)
                x -= a[l++];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// Optimal Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        int ans = 0, costSum = 0, left = 0;

        for (int right = 0; right < n; ++right)
        {
            costSum += abs(s[right] - t[right]);

            // Shrink the window if the cost exceeds maxCost
            while (costSum > maxCost)
            {
                costSum -= abs(s[left] - t[left]);
                ++left;
            }

            // Update the maximum length of the valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};