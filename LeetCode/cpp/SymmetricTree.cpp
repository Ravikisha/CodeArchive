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
    bool isSymmetric(TreeNode *root)
    {
        function<bool(TreeNode *, TreeNode *)> dfs =
            [&](TreeNode *left, TreeNode *right) -> bool
        {
            if (!left && !right)
                return true;
            if (!left || !right)
                return false;
            return (left->val == right->val && dfs(left->right, right->left) &&
                    dfs(left->left, right->right));
        };
        return dfs(root->left, root->right);
    }
};