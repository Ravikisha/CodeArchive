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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        function<void(TreeNode *, vector<string>)> dfs = [&](TreeNode *node, vector<string> path)
        {
            if (!node)
                return;
            if (node->left == NULL && node->right == NULL)
            {
                string ans = "";
                for (const auto &n : path)
                {
                    ans.append(n).append("->");
                }
                ans += to_string(node->val);
                result.push_back(ans);
                return;
            }
            path.push_back(to_string(node->val));
            dfs(node->left, path);
            dfs(node->right, path);
        };
        dfs(root, {});
        return result;
    }
};

// Better Solution
class Solution {
public:
    void helper(TreeNode* root, string s, vector<string>& ans) {
        if(root == NULL) return;
        string a = to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            s += a;
            ans.push_back(s);
            return;
        }
        helper(root->left, s+a+"->", ans);
        helper(root->right, s+a+"->", ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};