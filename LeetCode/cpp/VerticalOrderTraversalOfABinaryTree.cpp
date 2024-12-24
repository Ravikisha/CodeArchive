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
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push(make_pair(root, make_pair(0, 0)));
        while (!todo.empty())
        {
            pair<TreeNode *, pair<int, int>> p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
            {
                todo.push(make_pair(node->left, make_pair(x - 1, y + 1)));
            }
            if (node->right)
            {
                todo.push(make_pair(node->right, make_pair(x + 1, y + 1)));
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};