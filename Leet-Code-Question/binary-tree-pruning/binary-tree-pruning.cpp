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
    int solve(TreeNode* root){
        if(!root) return 0;
        
        if(!root->left && !root->right) {
            if(root->val==0){
                root->val=-1;
                return 0;
            } 
            
            return 1;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        if(left==0 && right==0 && root->val == 0){
            root->val=-1;
            return 0;
        }
        
        return 1;
        
    }
    
    TreeNode* remove(TreeNode* root){
        if(!root || root->val==-1) return NULL;
        
        root->left = remove(root->left);
        root->right = remove(root->right);
        
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        solve(root);
        
        return remove(root);
        // return root;
    }
};