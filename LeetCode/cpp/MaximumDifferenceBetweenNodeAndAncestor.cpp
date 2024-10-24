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
    // Space Complexity: O(n)
public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root)
            return 0;

        function<int(TreeNode *, int, int)> helper = [&](TreeNode *node, int minValue, int maxValue)
        {
            if (!node)
                return maxValue - minValue;

            // Update min and max based on the current node
            minValue = min(minValue, node->val);
            maxValue = max(maxValue, node->val);

            // Recursively compute for left and right subtrees
            int leftDiff = helper(node->left, minValue, maxValue);
            int rightDiff = helper(node->right, minValue, maxValue);

            // Return the maximum difference found in either subtree
            return max(leftDiff, rightDiff);
        };

        // Start the recursion with the root's value as both min and max
        return helper(root, root->val, root->val);
    }
};