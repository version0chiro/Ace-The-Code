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
public:vector<int> items;
    int i=0;
    
    void solve(TreeNode* root){
        if(!root) return;
        
        solve(root->left);
        items.push_back(root->val);
        solve(root->right);
    }
    
    void solve2(TreeNode* root){
        if(!root) return;
        
        solve2(root->left);
        root->val=items[i];
        i++;
        // items.push_back(root->val);
        solve2(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        sort(items.begin(),items.end());
        solve2(root);
    }
};