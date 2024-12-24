/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> umap;
        markParent(root, umap);
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (umap[curr] && !visited[umap[curr]])
                {
                    q.push(umap[curr]);
                    visited[umap[curr]] = true;
                }
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};