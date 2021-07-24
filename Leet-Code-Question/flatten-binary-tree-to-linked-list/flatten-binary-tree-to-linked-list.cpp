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
    vector<int> preorder;
    void inOrder(TreeNode* root){
        if(!root) return;
        preorder.push_back(root->val);
        inOrder(root->left);

        inOrder(root->right);
    }
    int i=0;
    void solve(TreeNode* root){
        if(!root || i==preorder.size()) return;
        
        root->val=preorder[i];
        i++;
        root->left=NULL;
        if(!root->right && i<preorder.size())
            root->right = new TreeNode();
        solve(root->right);
        
    }
    void flatten(TreeNode* root) {
        inOrder(root);
        solve(root);
    }
};