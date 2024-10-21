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
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        function<TreeNode *(int, int)> helper = [&](int l, int r) -> TreeNode *
        {
            if (l > r)
                return NULL;
            int m = l + (r - l) / 2;
            TreeNode *root = new TreeNode(nums[m]);
            root->left = helper(l, m - 1);
            root->right = helper(m + 1, r);
            return root;
        };
        return helper(0, nums.size() - 1);
    }
};