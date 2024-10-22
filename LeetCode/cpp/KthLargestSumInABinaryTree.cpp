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
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        // Min-heap to store the top k largest sums
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // Perform level-order traversal
        while (!q.empty()) {
            int qLen = q.size();
            long long sum = 0;  // Use long long to handle large sums
            
            // Sum all nodes' values at the current level
            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Maintain only the top k largest sums in the min-heap
            pq.push(sum);
            if (pq.size() > k) {
                pq.pop();  // Remove the smallest sum if heap size exceeds k
            }
        }
        
        // If we have fewer than k levels, return -1
        if (pq.size() < k) return -1;
        
        // The top of the heap is the k-th largest sum
        return pq.top();
    }
};