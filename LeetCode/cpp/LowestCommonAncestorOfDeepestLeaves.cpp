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
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        int deepestLevel = 0;
        TreeNode *result;

        function<int(TreeNode *, int)> findDeepestLevel = [&](TreeNode *node, int level)
        {
            deepestLevel = max(deepestLevel, level);
            if (!node)
                return level;
            int leftLevel = findDeepestLevel(node->left, level + 1);
            int rightLevel = findDeepestLevel(node->right, level + 1);

            if (leftLevel == rightLevel && leftLevel == deepestLevel)
            {
                result = node;
            }
            return max(leftLevel, rightLevel);
        };
        findDeepestLevel(root, 1);
        return result;
    }
};