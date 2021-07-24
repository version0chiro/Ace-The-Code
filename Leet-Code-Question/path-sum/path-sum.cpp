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
    bool solve(TreeNode* root,int targetSum,int count){
        if(!root){
            return false;
        }
        if(!root->left && !root->right && count+root->val==targetSum){
            return true;
        }
        
        return solve(root->left,targetSum,count+root->val) || solve(root->right,targetSum,count+root->val);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int count=0;
        return solve(root,targetSum,count);
    }
};