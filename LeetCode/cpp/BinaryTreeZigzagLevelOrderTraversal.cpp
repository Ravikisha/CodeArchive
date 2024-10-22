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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int level)
        {
            // Base case
            if (!node)
                return;
            // If the current level is equal to the size of the result vector, then we need to add a new vector to the result vector
            if (result.size() == level)
                result.push_back(vector<int>());
            // If the level is even, then we need to add the value to the end of the vector
            if (!(level & 1))
            {
                result[level].push_back(node->val);
            }
            // If the level is odd, then we need to add the value to the beginning of the vector
            else
            {
                result[level].insert(result[level].begin(), node->val);
            }
            dfs(node->left, level + 1);
            dfs(node->right, level + 1);
        };
        dfs(root, 0);
        return result;
    }
};