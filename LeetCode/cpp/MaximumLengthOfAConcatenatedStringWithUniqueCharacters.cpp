class Solution
{
    // Time Complexity: O(2^n)
    // Space Complexity: O(2^n)
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int maxLength(vector<string> &arr)
    {
        int ans = 0;
        int n = arr.size();

        for (int i = 0; i < (1 << n); i++)
        {
            int cur_ans = 0;
            vector<int> f(26, 0);

            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    cur_ans += arr[j].size();

                    for (auto x : arr[j])
                        ++f[x - 'a'];
                }
            }

            bool ok = 1;
            for (auto x : f)
            {
                if (x > 1)
                {
                    ok = 0;
                    break;
                }
            }

            if (ok)
                ans = max(ans, cur_ans);
        }

        return ans;
    }
};

// Backtracking Solution
class Solution
{
    // Time Complexity: O(2^n)
    // Space Complexity: O(2^n)
public:
    int maxLength(vector<string> &arr)
    {
        int maxLen = 0;

        // Helper function to check if a string has all unique characters
        auto isUnique = [](const string &s)
        {
            unordered_set<char> charSet;
            for (char c : s)
            {
                if (charSet.count(c))
                    return false;
                charSet.insert(c);
            }
            return true;
        };

        // Backtracking function to explore combinations
        function<void(int, string)> backtrack = [&](int index, string current)
        {
            // Base case: update max length if the current string is valid and unique
            if (isUnique(current))
            {
                maxLen = max(maxLen, (int)current.size());
            }
            else
            {
                return; // Stop if current combination is invalid
            }

            // Recursive case: try adding each subsequent string in `arr`
            for (int i = index; i < arr.size(); i++)
            {
                backtrack(i + 1, current + arr[i]);
            }
        };

        // Start backtracking from the first index with an empty current string
        backtrack(0, "");

        return maxLen;
    }
};