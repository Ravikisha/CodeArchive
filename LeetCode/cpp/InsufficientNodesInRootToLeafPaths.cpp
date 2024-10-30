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
    // Space Complexity: O(h)
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit, int pathSum = 0)
    {
        if (!root)
            return nullptr;

        // Add the current node's value to the cumulative path sum
        pathSum += root->val;

        // If the node is a leaf, check if its path sum is less than the limit
        if (!root->left && !root->right)
        {
            // If the path sum is less than the limit, prune this leaf
            return pathSum < limit ? nullptr : root;
        }

        // Recursively check and prune the left and right subtrees
        root->left = sufficientSubset(root->left, limit, pathSum);
        root->right = sufficientSubset(root->right, limit, pathSum);

        // If both children are pruned, prune this node as well
        if (!root->left && !root->right)
            return nullptr;

        // If the node has at least one non-pruned subtree, keep it
        return root;
    }
};