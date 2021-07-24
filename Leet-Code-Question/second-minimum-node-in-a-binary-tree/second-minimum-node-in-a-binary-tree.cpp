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
    set<int> s;
    void inOrder(TreeNode* root){
        if(!root) return;
        
        s.insert(root->val);
        inOrder(root->left);
        inOrder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inOrder(root);
        int p=0;
        
        for(auto a:s){
            if(p==1) return a;
            p++;
        }
        
        return -1;
        
    }
};