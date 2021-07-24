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
    TreeNode* solve(vector<int>& preorder,int s,int e,int &idx,unordered_map<int,int> &mp){
        if(s>e)
           return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        int m=mp[preorder[idx]];
        idx++;
        root->left=solve(preorder,s,m-1,idx,mp);
        root->right=solve(preorder,m+1,e,idx,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s = 0;
        int e = inorder.size()-1;
        int idx=0;
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        
        TreeNode* root = solve(preorder,s,e,idx,m);
        
        return root;
    }
};