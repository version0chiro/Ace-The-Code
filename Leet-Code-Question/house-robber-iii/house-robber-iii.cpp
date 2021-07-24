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
    int solve(TreeNode* root,int &l,int &r){
        if(!root) return 0;
        
        int ll=0,lr=0,rr=0,rl=0;
        l=solve(root->left,ll,lr);
        r=solve(root->right,rl,rr);
        
        return max(root->val+ll+lr+rr+rl,l+r);
    }
    int rob(TreeNode* root) {
        int l,r;
        return solve(root,l,r);
    }
};