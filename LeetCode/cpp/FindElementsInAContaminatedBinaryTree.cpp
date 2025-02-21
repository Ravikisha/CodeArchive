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
class FindElements
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    TreeNode *myroot;
    FindElements(TreeNode *root)
    {
        myroot = root;
        function<void(TreeNode *, int)> traverse = [&](TreeNode *node, int v)
        {
            node->val = v;
            if (node->left)
                traverse(node->left, 2 * v + 1);
            if (node->right)
                traverse(node->right, 2 * v + 2);
        };
        traverse(root, 0);
    }

    bool find(int target)
    {
        if (!myroot)
            return false;
        function<bool(TreeNode *)> traverse = [&](TreeNode *node)
        {
            if (target == node->val)
                return true;
            bool found = false;
            if (node->left)
                found |= traverse(node->left);
            if (node->right)
                found |= traverse(node->right);
            return found;
        };
        return traverse(myroot);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */