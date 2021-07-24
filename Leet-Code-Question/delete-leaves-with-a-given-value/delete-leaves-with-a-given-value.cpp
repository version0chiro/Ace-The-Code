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
    void solve(TreeNode* root,int target){
        if(!root) return;
        
        solve(root->left,target);
        solve(root->right,target);
        
        
//         cout<<"current node: "<<root->val;
//         if(root->left)
//         cout<<" left node:"<<root->left->val;
//         if(root->right)
//         cout<<" right node:"<<root->right->val;
        
//         cout<<" \n";
        
        if(((!root->left && !root->right) || (((root->left && root->left->val==-1) || !root->left) && (!root->right || (root->right && root->right->val==-1)) )) && root->val==target)
            root->val=-1;
        
        if(root->left && root->left->val==-1) root->left =NULL;
        if(root->right && root->right->val==-1) root->right = NULL;
        // cout<<root->val<<" ";
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root,target);
        if(root->val==-1)
            return NULL;
        return root;
    }
};