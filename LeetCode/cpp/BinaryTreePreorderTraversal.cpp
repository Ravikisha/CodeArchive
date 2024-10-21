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

// Recursive Approach
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    void preorder(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};

// Iterative Approach

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr || !(st.empty()))
        {
            if (curr)
            {
                result.push_back(curr->val);
                st.push(curr->right);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
            }
        }
        return result;
    }
};