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
    void solve(TreeNode* root,vector<string> &ans,string temp){
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }
        
        temp+=to_string(root->val)+"->";
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root,ans,"");
        return ans;
    }
};