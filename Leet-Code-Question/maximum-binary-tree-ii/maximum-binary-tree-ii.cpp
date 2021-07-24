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
    vector<int> tempVec;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        tempVec.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        inorder(root);
        tempVec.push_back(val);
        vector<TreeNode*> stk;
        
        for(int i=0;i<tempVec.size();i++){
            TreeNode* curr = new TreeNode(tempVec[i]);
            while(!stk.empty() && stk.back()->val<tempVec[i]){
                curr->left = stk.back();
                stk.pop_back();
            }
            if(!stk.empty()){
                stk.back()->right=curr;
            }
            stk.push_back(curr);
            
        }
        return stk.front();
    }
};