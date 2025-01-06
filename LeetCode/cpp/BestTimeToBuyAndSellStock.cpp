class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

/*
Explanation:
1. First we choose the first element as the minimum element.
2. Then we iterate through the array and calculate the cost of the stock on that day.
3. We update the minimum element and the maximum profit.
4. Finally we return the maximum profit.
*/