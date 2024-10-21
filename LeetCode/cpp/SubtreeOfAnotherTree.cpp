/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    // Time Complexity: O(n * m)
    // Space Complexity: O(n)
    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        // this version not allow search t in s's subtree,
        // it just compare whether s equals to t
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return false;
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    // Time Complexity: O(n * m)
    // Space Complexity: O(n)
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        // both not empty
        // s and t are same tree
        if ((root->val == subRoot->val) &&
            isSameTree(root->left, subRoot->left) &&
            isSameTree(root->right, subRoot->right))
            return true;
        // if s and t are not the same,
        // keep find t in s's subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};