class Solution
{
    // Time Complexity: O(mlogn)
    // Space Complexity: O(1)
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> result;
        int m = spells.size();
        for (int i = 0; i < m; i++)
        {
            int n = potions.size();
            int low = 0, high = n - 1;
            int index = n;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if ((long long)spells[i] * (long long)potions[mid] >= (long long)success)
                {
                    high = mid - 1;
                    index = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            result.push_back(n - index);
        }
        return result;
    }
};

/*
Explanation:
1. Sort the potions array.
2. For each spell, find the number of potions that can be used to make the spell successful.
3. Use binary search to find the number of potions that can be used to make the spell successful.
4. The number of successful pairs for each spell is potions.size() - index.
5. Return the result.
*/