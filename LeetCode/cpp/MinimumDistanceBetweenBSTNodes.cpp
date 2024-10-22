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
    int minDiffInBST(TreeNode *root)
    {
        if (!root)
            return 0;
        TreeNode *prev = NULL;
        int result = INT_MAX;
        function<void(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (!node)
                return;
            dfs(node->left);
            if (prev)
            {
                result = min(result, node->val - prev->val);
            }
            prev = node;
            dfs(node->right);
        };
        dfs(root);
        return result;
    }
};