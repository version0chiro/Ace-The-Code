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
    int solve(TreeNode* root,int pre,int targetSum){
        if(!root) return 0;
        int cur = pre+root->val;
        return (cur==targetSum) + solve(root->left,cur,targetSum) + solve(root->right,cur,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        
        return solve(root,0,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
    
};