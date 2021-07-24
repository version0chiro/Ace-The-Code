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
    void traverse(TreeNode* root,vector<int> &leafs){
        if(!root) return;
        
        traverse(root->left,leafs);
        if(!root->left && !root->right) leafs.push_back(root->val);
        traverse(root->right,leafs);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1,tree2;
        
        traverse(root1,tree1);
        traverse(root2,tree2);
        if(tree1.size()!=tree2.size()) return false;
        for(int i=0;i<tree1.size();i++){
            if(tree1[i]!=tree2[i]) return false;
        }
        
        
        return true;
        
    }
};