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
    // Time Complexity: O(n) for both serialization and deserialization
    // Space Complexity: O(n) for both serialization and deserialization
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        return to_string(root->val) + " " + serialize(root->left) +
               serialize(root->right);
    }

    TreeNode *deserialize(queue<string> &q, int lower, int upper)
    {
        if (q.empty())
            return nullptr;

        int val = stoi(q.front());

        if (val < lower || val > upper)
            return nullptr;

        // only pop the string after ensuring it can be used here
        q.pop();

        TreeNode *node = new TreeNode(val);
        node->left = deserialize(q, lower, val);
        node->right = deserialize(q, val, upper);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        istringstream ss(data);
        queue<string> q;
        string s;

        while (ss >> s)
        {
            q.push(s);
        }

        return deserialize(q, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;