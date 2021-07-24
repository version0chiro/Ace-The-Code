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
    
    void solve(TreeNode* root, int x,int &xd,int y,int &yd,int depth,TreeNode* prev,int &p1,int &p2){
        if(!root) return;
        
        solve(root->left,x,xd,y,yd,depth+1,root,p1,p2);
        if(root->val==x){
            xd=depth;
            p1=prev->val;
        }
        
        if(root->val==y){
            yd=depth;
            p2=prev->val;
        }
        
        solve(root->right,x,xd,y,yd,depth+1,root,p1,p2);
        
        

    }
    bool isCousins(TreeNode* root, int x, int y) {
        int xd,yd;
        int p1,p2;
        solve(root,x,xd,y,yd,0,root,p1,p2);
        
        return xd==yd && p1!=p2;
    }
};