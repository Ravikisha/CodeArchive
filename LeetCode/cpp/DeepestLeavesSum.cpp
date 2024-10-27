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
    int deepestLeavesSum(TreeNode *root)
    {
        int deepestLevel = -1;
        int sum = 0;
        function<void(TreeNode *, int)> findDeepest = [&](TreeNode *node, int level)
        {
            if (!node)
                return;
            if (level > deepestLevel)
            {
                deepestLevel = level;
                sum = node->val;
            }
            else if (level == deepestLevel)
            {
                sum += node->val;
            }
            findDeepest(node->left, level + 1);
            findDeepest(node->right, level + 1);
        };
        findDeepest(root, 1);
        return sum;
    }
};