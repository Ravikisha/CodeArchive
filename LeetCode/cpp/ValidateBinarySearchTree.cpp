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
    bool inOrder(TreeNode *node, long long &last)
    {
        if (!node)
            return true;
        if (!inOrder(node->left, last))
            return false;
        if (node->val <= last)
            return false;
        last = node->val;

        if (!inOrder(node->right, last))
            return false;
        return true;
    }

    bool isValidBST(TreeNode *root)
    {
        long long last = LLONG_MIN;
        return inOrder(root, last);
    }
};