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

// Recursive Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    void postorder(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};

// Iterative Solution

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        stack<bool> visit;
        vector<int> result;
        TreeNode *curr = root;
        st.push(root);
        visit.push(false);
        bool visited = false;
        while (!st.empty())
        {
            curr = st.top();
            st.pop();
            visited = visit.top();
            visit.pop();
            if (curr)
            {
                if (visited)
                {
                    result.push_back(curr->val);
                }
                else
                {
                    st.push(curr);
                    visit.push(true);
                    st.push(curr->right);
                    visit.push(false);
                    st.push(curr->left);
                    visit.push(false);
                }
            }
        }
        return result;
    }
};