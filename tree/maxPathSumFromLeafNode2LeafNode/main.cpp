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
public:
    int res = INT_MIN;
    int solve(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = solve(root->left);
        int r = solve(root->right);

        int temp = (root->val + max(l, r));
        if (!root->left && !root->right)
        {
            temp = max(temp, root->val);
        }

        int ans = max(temp, root->val + l + r);

        res = max(ans, res);

        return temp;
    }
    int maxPathSum(TreeNode *root)
    {
        solve(root);

        return res;
    }
};