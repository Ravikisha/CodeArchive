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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int qLen = q.size();
            int level_last;
            for (int i = 0; i < qLen; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                level_last = curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            result.push_back(level_last);
        }
        return result;
    }
};