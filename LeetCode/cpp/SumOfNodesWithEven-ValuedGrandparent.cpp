class Solution {
public:
    // Function to find the sum of values of nodes whose grandparent nodes have even values
    int sumEvenGrandparent(TreeNode* root) {
        
        // Define a recursive lambda function `dfs` to traverse the tree
        // `x` represents the parent node's value, which is used to check if the grandparent is even
        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int x) {
            
            // Base case: If the current node is null, return 0 (no value to add)
            if (!root) {
                return 0;
            }
            
            // Recursively calculate the sum of values from the left and right subtrees
            // Pass the current node's value as `x` to the next level (child nodes) to track the grandparent's value
            int ans = dfs(root->left, root->val) + dfs(root->right, root->val);
            
            // If `x` (grandparent's value) is even, add the values of the left and right children (if they exist)
            if (x % 2 == 0) {
                if (root->left) {
                    ans += root->left->val;  // Add the left child's value if grandparent is even
                }
                if (root->right) {
                    ans += root->right->val; // Add the right child's value if grandparent is even
                }
            }
            
            // Return the accumulated sum for the current node
            return ans;
        };
        
        // Call the dfs function starting from the root node with an initial grandparent value (e.g., 1, which is odd)
        return dfs(root, 1);
    }
};
