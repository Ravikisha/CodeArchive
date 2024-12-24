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
    // Time Complexity: O(N)
    // Space Complexity: O(N)
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool seenNull = false; // Flag to indicate if a NULL node has been encountered
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node)
            {
                if (seenNull)
                    return false; // If we saw NULL before and now see a non-NULL node
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                seenNull = true; // Mark that we've seen a NULL node
            }
        }
        return true;
    }
};