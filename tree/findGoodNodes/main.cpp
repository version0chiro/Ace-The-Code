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
    int count;
    
    void solve(TreeNode* root,int maxSoFar){
        if(!root) return;
        // cout<<"root currently->"<<root->val<<"\n";
        if(root->val>=maxSoFar){
            // cout<<root->val<<" "<<maxSoFar<<" cahcngin"<<"\n";
            count++;
            maxSoFar=root->val;
        } 
        
        solve(root->left,maxSoFar);
        solve(root->right,maxSoFar);
            
        
        
    }
    int goodNodes(TreeNode* root) {
        count=0;
        solve(root,root->val);
        return count;
    }
};