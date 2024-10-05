class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> l(n, 1), r(n, 1);
        int left = 1;
        for (int i = 0; i < n; i++)
        {
            l[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            r[i] = right;
            right *= nums[i];
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++)
            result[i] = l[i] * r[i];
        return result;
    }
};

/*
Explaination:
1. Create two arrays l and r of size n and initialize them with 1.
2. Traverse the array from left to right and store the product of all elements to the left of the current element in l.
3. Traverse the array from right to left and store the product of all elements to the right of the current element in r.
4. The product of all elements except the current element is the product of the elements in l and r.
5. Return the result array.

Example:
nums = [1, 2, 3, 4]
l = [1, 1, 2, 6]
r = [24, 12, 4, 1]
result[i] = l[i] * r[i] = [24, 12, 8, 6]

*/