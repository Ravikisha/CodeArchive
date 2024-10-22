/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive Approach
class Solution
{
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h), where h is the height of the tree
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (!root)
            return nullptr;

        if (root->val == p->val)
            return p;

        if (root->val == q->val)
            return q;

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        else if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        else
            return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Iterative Approach
class Solution
{
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(1)
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            else if (p->val < curr->val && q->val < curr->val)
                curr = curr->left;
            else
                return curr;
        }
        return NULL;
    }
};