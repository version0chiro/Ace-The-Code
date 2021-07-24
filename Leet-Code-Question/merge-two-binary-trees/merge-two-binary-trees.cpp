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
    
    void solve(TreeNode* root1,TreeNode* root2,TreeNode* t){
        if(root1 && root2){
            if(root1->left || root2->left){
                t->left= new TreeNode();
                solve(root1->left,root2->left,t->left);
            }
            if(root2->right || root1->right){
                t->right= new TreeNode();
                solve(root1->right,root2->right,t->right);
                
            }
            t->val=root1->val+root2->val;


        }
        
        else if(root1){
            t->val=root1->val;
            if(root1->left){
                t->left= new TreeNode();
                solve(root1->left,NULL,t->left);
            }
            if(root1->right){
                t->right= new TreeNode();
                solve(root1->right,NULL,t->right);
            }
            return;
        }
        
        else if(root2){
            t->val=root2->val;
            if(root2->left){
                t->left= new TreeNode();
                solve(NULL,root2->left,t->left);
            }
            if(root2->right){
                t->right= new TreeNode();
                solve(NULL,root2->right,t->right);
            }
            return;
        }
        else{
            t=NULL;
            return;
        }
        
        return;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        TreeNode* t = new TreeNode();
        
        solve(root1,root2,t);
        
        
        return t;
        
        
    }
};