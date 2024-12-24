/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string result = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == NULL)
                result.append("#,");
            else
                result.append(to_string(node->val) + ',');
            if (node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));