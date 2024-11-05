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
class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int minDepth(TreeNode* root) {
        int res =  INT_MAX;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int level){
            if(!node) return;
            if(node->left == NULL && node->right == NULL)
                res = min(res, level);
            if(node->left) dfs(node->left, level+1);
            if(node->right) dfs(node->right, level+1);
        };
        dfs(root, 1);
        return res != INT_MAX ? res : 0;
    }
};