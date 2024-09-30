class Solution
{
    // Time complexity: O(n*log(max(piles)))
    // Space complexity: O(1)
public:
    long long timeConsume(vector<int> &piles, int n)
    {
        long long sum = 0;
        for (int pile : piles)
        {
            sum += (pile + n - 1) / n;
        }
        return sum;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int result = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cout << timeConsume(piles, mid);
            if (timeConsume(piles, mid) <= (long long)h)
            {
                result = min(result, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};