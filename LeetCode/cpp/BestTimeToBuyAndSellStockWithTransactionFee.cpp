class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Bottom-up Dynamic Programming (Tabulation)
    // Space Optimized
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
        aheadNotBuy = aheadBuy = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            // sell
            curNotBuy = max(prices[i] - fee + aheadBuy, 0 + aheadNotBuy);
            // buy
            curBuy = max(-prices[i] + aheadNotBuy, 0 + aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};
