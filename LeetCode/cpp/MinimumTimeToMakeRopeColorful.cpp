class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int l = 0, res = 0;
        for (int i = 1; i < n; i++)
        {
            if (colors[l] == colors[i])
            {
                if (neededTime[l] < neededTime[i])
                {
                    res += neededTime[l];
                    l = i;
                }
                else
                {
                    res += neededTime[i];
                }
            }
            else
            {
                l = i;
            }
        }
        return res;
    }
};

/*
Explaination:
1. We will iterate over the colors and neededTime arrays.
2. If the colors at index l and i are same, then we will check which of the two neededTime is less.
3. If neededTime[l] is less than neededTime[i], then we will add neededTime[l] to the result and update l to i.
4. If neededTime[i] is less than neededTime[l], then we will add neededTime[i] to the result.
5. If the colors at index l and i are different, then we will update l to i.
6. Finally, we will return the result.
*/