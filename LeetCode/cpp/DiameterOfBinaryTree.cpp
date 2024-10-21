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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;

        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int
        {
            if (!node)
                return 0;

            int left = dfs(node->left);
            int right = dfs(node->right);

            ans = max(ans, left + right);

            return max(left, right) + 1;
        };

        dfs(root);

        return ans;
    }
};

/*
Explaination:
1. Create a ans variable to store the diameter of the binary tree.
2. Create a lambda function dfs which takes a TreeNode* as input and returns an integer.
3. If the node is NULL, return 0.
4. Recursively calculate the left and right height of the binary tree.
5. Update the ans variable with the maximum of the current ans and the sum of left and right height.
6. Return the maximum of left and right height + 1.
7. Call the dfs function with the root node.
8. Return the ans variable.
*/