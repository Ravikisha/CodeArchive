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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// Iterative Solution

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            // Swap the left and right children
            TreeNode *temp = current->left;
            current->left = current->right;
            current->right = temp;

            // Push the children into the queue if they are not null
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        return root;
    }
};