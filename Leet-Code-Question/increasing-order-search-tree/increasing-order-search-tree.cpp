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
    vector<int> ans;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    
    void newTree(TreeNode* root,int i){
        if(i==ans.size()){
            return;
        }
        root->right= new TreeNode(ans[i]);
        newTree(root->right,i+1);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        
        TreeNode* newRoot = new TreeNode(ans[0]);
        
        newTree(newRoot,1);
        
        return newRoot;
        
    }
};