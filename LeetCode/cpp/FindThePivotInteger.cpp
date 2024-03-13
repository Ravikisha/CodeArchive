class Solution
{
public:
    int pivotInteger(int n)
    {
        float ans1 = sqrt((n * (n + 1)) / 2);
        int ans2 = int(ans1);
        if (ans1 - ans2 == 0)
            return ans1;
        return -1;
    }
};