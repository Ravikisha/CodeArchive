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
    // Time Complexity: O(h) where h is the height of the tree
    // Space Complexity: O(h) where h is the height of the tree
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            // Find the min from right subtree
            TreeNode *curr = root->right;
            while (curr->left)
                curr = curr->left;
            root->val = curr->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};