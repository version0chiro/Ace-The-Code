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
    int traverse(TreeNode* root,int prev){
        if(!root || root->val!=prev) return 0;
        
        return 1+max(traverse(root->left,root->val),traverse(root->right,root->val));
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        
        return max(traverse(root->left,root->val)+traverse(root->right,root->val),
                   max(longestUnivaluePath(root->left),longestUnivaluePath(root->right))
                  );
    }
};