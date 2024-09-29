class Solution
{
    // Time Complexity: O(1) as the number of elements in the array is constant and very small
    // Space Complexity: O(1) as the number of elements in the array is constant and very small
public:
    string intToRoman(int num)
    {
        int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L",
                        "XC", "C", "CD", "D", "CM", "M"};
        int i = 12;
        string result = "";
        while (num > 0)
        {
            int div = num / nums[i];
            num = num % nums[i];
            while (div--)
            {
                result += sym[i];
            }
            i--;
        }
        return result;
    }
};