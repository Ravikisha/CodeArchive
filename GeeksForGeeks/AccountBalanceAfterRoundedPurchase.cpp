class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    int accountBalanceAfterPurchase(int purchaseAmount)
    {
        return 100 - (purchaseAmount + 5) / 10 * 10;
    }
};