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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int qLen = q.size();
            double average = 0;
            double elementCount = 0;
            for (int i = 0; i < qLen; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                average += curr->val;
                elementCount++;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            result.push_back(average / elementCount);
        }
        return result;
    }
};