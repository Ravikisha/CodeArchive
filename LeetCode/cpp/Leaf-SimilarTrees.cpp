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
// Recursive Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        function<void(TreeNode *, vector<int> &)> dfs = [&](TreeNode *root,
                                                            vector<int> &leaf)
        {
            if (!root)
                return;
            if (!root->left && !root->right)
            {
                leaf.push_back(root->val);
            }
            dfs(root->left, leaf);
            dfs(root->right, leaf);
        };
        vector<int> leaf1, leaf2;
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        return leaf1 == leaf2;
    }
};

// Iterative Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    void build_leaf_values(TreeNode *root, vector<int> *leaf_values)
    {
        stack<TreeNode *> stk;
        TreeNode *cur;

        stk.push(root);
        while (!stk.empty())
        {
            cur = stk.top();
            stk.pop();

            if (cur->left == NULL && cur->right == NULL)
            {
                leaf_values->push_back(cur->val);
            }
            else
            {
                if (cur->right)
                    stk.push(cur->right);
                if (cur->left)
                    stk.push(cur->left);
            }
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaf_values1, leaf_values2;

        build_leaf_values(root1, &leaf_values1);
        build_leaf_values(root2, &leaf_values2);

        if (leaf_values1 == leaf_values2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};