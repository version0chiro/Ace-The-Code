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
    int sum=0;
    void solve(TreeNode* root,bitset<32> s){
        if(!root){
            return;  
        } 
        // cout<<s<<" \n";
        s[0]=root->val;
        if(!root->left && !root->right){
            // cout<<s<<" ";
            sum+=s.to_ulong();
            return;
        }
        
        
        solve(root->left,s<<1);
        solve(root->right,s<<1);
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        bitset<32> s; 
        solve(root,s);
        
        return sum;
    }
};