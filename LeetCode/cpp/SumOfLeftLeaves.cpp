/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = 0;
        function<void(TreeNode *, bool)> rSumOfLeftLeaves = [&](TreeNode *node, bool isLeft)
        {
            if (node->left == NULL && node->right == NULL && isLeft)
            {
                ans += node->val;
            }
            if (node->left)
            {
                rSumOfLeftLeaves(node->left, true);
            }
            if (node->right)
            {
                rSumOfLeftLeaves(node->right, false);
            }
        };
        rSumOfLeftLeaves(root, false);

        return ans;
    }
};