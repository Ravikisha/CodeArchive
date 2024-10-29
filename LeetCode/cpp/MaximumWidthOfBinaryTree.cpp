class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        // Queue to hold pairs of TreeNode pointers and their position indices
        queue<pair<TreeNode *, int>> q;

        // Initialize queue with the root node at position 1
        q.push({root, 1});

        // Variable to store the maximum width of the binary tree
        int ans = 0;

        // Perform level-order traversal
        while (!q.empty())
        {
            // Calculate the width of the current level: last index - first index + 1
            ans = max(ans, q.back().second - q.front().second + 1);

            // Store the index of the first node at this level to normalize indices
            int i = q.front().second;

            // Process each node on the current level
            for (int n = q.size(); n; --n)
            {
                // Pop the front node of the queue
                auto p = q.front();
                q.pop();

                // Get the current node and its normalized position index
                root = p.first;
                int j = p.second;

                // If there is a left child, push it with normalized index (2*j - 2*i)
                if (root->left)
                    q.push({root->left, (j << 1) - (i << 1)});

                // If there is a right child, push it with normalized index (2*j + 1 - 2*i)
                if (root->right)
                    q.push({root->right, (j << 1 | 1) - (i << 1)});
            }
        }

        // Return the maximum width encountered
        return ans;
    }
};
