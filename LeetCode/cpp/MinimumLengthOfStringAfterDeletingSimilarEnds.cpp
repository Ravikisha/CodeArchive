// Optimal Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j])
        {
            while (i + 1 < j && s[i] == s[i + 1])
            {
                ++i;
            }
            while (i < j - 1 && s[j] == s[j - 1])
            {
                --j;
            }
            ++i;
            --j;
        }
        return max(0, j - i + 1);
    }
};

/*
Explaination:
1. We are given a string s.
2. We need to find the minimum length of the string after deleting similar ends.
3. We will use two pointers i and j.
4. We will start from the beginning and end of the string.
5. We will check if the characters at i and j are same.
6. If they are same, we will increment i and decrement j.
7. If they are not same, we will return the length of the string from i to j.
8. If i is greater than or equal to j, we will return 0.
9. This is because there are no characters left in the string.
10. This is the optimal approach as it has O(n) time complexity and O(1) space complexity.
*/