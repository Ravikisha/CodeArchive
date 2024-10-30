/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(h) where h is the height of the tree
public:
    int sumRootToLeaf(TreeNode *root)
    {
        int sum = 0;
        function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int num)
        {
            if (!node)
                return;

            // Shift num left by 1 and add the current node value (building binary number)
            num = (num << 1) | node->val;

            // If we are at a leaf node, add num to the sum
            if (!node->left && !node->right)
            {
                sum += num;
                return;
            }

            // Recurse on left and right children
            dfs(node->left, num);
            dfs(node->right, num);
        };
        dfs(root, 0);
        return sum;
    }
};