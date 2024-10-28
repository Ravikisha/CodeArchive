class Solution
{
    // Time Complexity: O(4^n)
    // Space Complexity: O(n*4^n)
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        // If the total sum is not divisible by 4, we can't make a square
        if (sum % 4 != 0)
            return false;

        int length = sum / 4;
        vector<int> sides(4, 0);

        // Sort matchsticks in descending order
        sort(matchsticks.rbegin(), matchsticks.rend());

        // Backtracking function
        function<bool(int)> backtrack = [&](int i)
        {
            if (i == matchsticks.size())
                return (sides[0] == length && sides[1] == length && sides[2] == length && sides[3] == length);

            for (int j = 0; j < 4; j++)
            {
                // Skip if placing this matchstick would exceed the target length
                if (sides[j] + matchsticks[i] > length)
                    continue;

                // Place matchstick on side j
                sides[j] += matchsticks[i];

                // Recurse to next matchstick
                if (backtrack(i + 1))
                    return true;

                // Undo the placement
                sides[j] -= matchsticks[i];

                // Optimization: If the side is 0, no point in trying to place the matchstick on other sides
                if (sides[j] == 0)
                    break;
            }
            return false;
        };

        return backtrack(0);
    }
};