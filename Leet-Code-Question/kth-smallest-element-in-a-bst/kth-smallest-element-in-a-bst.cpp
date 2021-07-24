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
    int ans=0;
    int k_time=0;
    void solve(TreeNode* root){
        if(!root || k_time==0) return;
        
        solve(root->left);
        k_time--;
        if(k_time==0){
            
            ans=root->val;
            return;
        }
        
        // cout<<root->val<<" ";
        solve(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        k_time=k;
        solve(root);
        return ans;
    }
};