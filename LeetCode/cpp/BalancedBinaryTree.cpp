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
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    bool isBalanced(TreeNode *root)
    {
        function<pair<bool, int>(TreeNode *)> dfs =
            [&](TreeNode *node) -> pair<bool, int>
        {
            if (!node)
                return make_pair<bool, int>(true, 0);

            pair<bool, int> left = dfs(node->left);
            pair<bool, int> right = dfs(node->right);

            bool balanced = (left.first && right.first &&
                             abs(left.second - right.second) <= 1);
            return make_pair(balanced,
                             1 + max(left.second, right.second));
        };

        return dfs(root).first;
    }
};