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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        else if(!root->left && !root->right){
            return 1;
        }
        else if(!root->left && root->right){
            return 1+minDepth(root->right);
        }
        else if(root->left && !root->right){
            return 1+minDepth(root->left);
        }
        else if(root->left && root->right){
            int lDepth = minDepth(root->left);
            int rDepth = minDepth(root->right);
            return 1+min(lDepth,rDepth);    
    }
        return 1;}
};