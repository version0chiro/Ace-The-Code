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
    bool solve(TreeNode* left,TreeNode* right){
        // if(!left || )
        if(!left && !right) return true;
        if(!left || !right) return false;
        
        if(left->val!=right->val){
            return false;
        }
        
        return solve(left->left,right->right) && solve(left->right,right->left) && true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return solve(root->left,root->right);
    }
};