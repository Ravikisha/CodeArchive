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
    // Time Complexity: O(nlogk)
    // Space Complexity: O(n)
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq; // Min-heap to keep track of k largest sums
        queue<TreeNode *> q;
        q.push(root);

        // Level-order traversal
        while (!q.empty())
        {
            int qLen = q.size();
            long long sum = 0; // Use long long for large sums
            for (int i = 0; i < qLen; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            pq.push(sum);
            if (pq.size() > k)
            {
                pq.pop(); // Maintain the size of heap to be k
            }
        }

        // If there are fewer than k levels, return -1
        if (pq.size() < k)
            return -1;

        return pq.top(); // The k-th largest level sum
    }
};