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
    // Space Complexity : O(n)
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int result = -1;

        function<void(TreeNode *)> inorder = [&](TreeNode *node)
        {
            if (!node || count >= k)
                return;
            inorder(node->left);
            count++;
            if (count == k)
            {
                result = node->val;
                return;
            }
            inorder(node->right);
        };
        inorder(root);
        return result;
    }
};