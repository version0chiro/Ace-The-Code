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
    int countMax=0;
    
    void inOrder(TreeNode* root,int count,bool lastLeft){
        // cout<<count<<" ";
        if(!root) {
            count--;
            countMax=max(count,countMax);
            return;
        }else{
            countMax=max(count,countMax);
        }
        
        if(lastLeft){
            inOrder(root->left,1,true);
            inOrder(root->right,count+1,false);
        }else{
            inOrder(root->left,count+1,true);
            inOrder(root->right,1,false);
        }
        
    }
    
    int longestZigZag(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return 0;
        
        inOrder(root->left,1,true);
        inOrder(root->right,1,false);
        
        return countMax;
        
    }
};