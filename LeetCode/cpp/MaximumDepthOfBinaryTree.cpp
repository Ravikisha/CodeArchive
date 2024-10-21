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
// Recursive Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Iterative Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int level = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size(); // Store current level size
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                // Push the left and right children to the queue
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            level++; // Increment level after finishing a complete level
        }

        return level;
    }
};