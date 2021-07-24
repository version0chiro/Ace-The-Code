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
    void helper(TreeNode* root,vector<int> &ans,int d){
        if(!root) return;
        if(d>=ans.size()){
            ans.push_back(root->val);
        }
        helper(root->right,ans,d+1);
        helper(root->left,ans,d+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root,ans,0);
        return ans;
    }
};