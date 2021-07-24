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
    void traverse(TreeNode* root,int last,int d){
        if(!root) return;
        last=last*10+root->val;
        if(!root->left && !root->right) sum+=last;
        
        traverse(root->left,last,d+1);
        traverse(root->right,last,d+1);
    }
    int sumNumbers(TreeNode* root) {
        // int sum=0;
        
        traverse(root,0,0);
        
//         for(auto a:ans){
//             sum+=a;
//         }
        
        return sum;
    }
};