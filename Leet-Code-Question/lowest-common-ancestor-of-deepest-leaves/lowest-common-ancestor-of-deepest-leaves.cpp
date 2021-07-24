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
    vector<TreeNode*> deepestNode(TreeNode* root){
        
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> ans;
        while(q.size()){
            int s = q.size();
            vector<TreeNode*> temp;
            for(int i=0;i<s;i++){
                auto node = q.front();
                q.pop();
                temp.push_back(node);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                
            }
            ans=temp;
        }
        
        return ans;
    }
    
    TreeNode* LCS(TreeNode* root,vector<TreeNode*> &d_nodes){
        if(!root || find(d_nodes.begin(),d_nodes.end(),root)!=d_nodes.end()) return root;
        
        TreeNode* l = LCS(root->left,d_nodes);
        TreeNode* r = LCS(root->right,d_nodes);
        
        return !l?r:!r?l:root;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> d_nodes=deepestNode(root);
        // for(auto a:d_nodes){
        //     cout<<a->val<<" ";
        // }
        return LCS(root,d_nodes);
    }
};