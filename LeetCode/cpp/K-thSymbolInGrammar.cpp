// Optimal Solution
class Solution
{
    // Time Complexity: O(log(k))
    // Space Complexity: O(1)
public:
    int kthGrammar(int n, int k)
    {
        int cur = 0;
        int left = 1, right = pow(2, n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            int mid = (left + right) / 2;
            if (k <= mid)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
                if (cur == 1)
                {
                    cur = 0;
                }
                else
                {
                    cur = 1;
                }
            }
        }
        return cur;
    }
};
/*
Explaination: 
The first half of the string is the same as the original string, and the second half is the complement of the original string.

This form a binary tree, the root is 0, and the left child of the node is 0, the right child of the node is 1.

       0
      / \
     0   1
    / \ / \
    0  1 1  0

Steps:
1. We create two pointers left and right, which represent the range of the current string.
2. Left is 0 and right is 2^(n-1). {2^(n-1) is the number of nodes in the binary tree at level n}
3. We iterate from level 1 to n-1.
4. At each level, we calculate the mid of the range and check if k is less than or equal to mid.
5. If k is less than or equal to mid, we update right to mid and there is nothing to udpate in the current string cause the first half of the string is the same as the original string.
6. If k is greater than mid, we update left to mid+1 and update the current string to the complement of the original string.
7. Finally, we return the current string.
*/