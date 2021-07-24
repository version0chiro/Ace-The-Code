/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void search(TreeNode* root,TreeNode* target,vector<TreeNode*> &m){
        while(root){
            m.push_back(root);
            if(root==target){
                return;
            }
            else if(root->left && target->val<root->val){
                root=root->left;
            }else if(root->right && target->val>root->val){
                root=root->right;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* tempRoot = root;
        vector<TreeNode*> m1;
        vector<TreeNode*> m2;
        search(root,p,m1);
        search(root,q,m2);
        
        TreeNode* ans = root;
        
        int i=0,j=0;
        // for(auto a:m1){
        //     cout<<a->val<<" ";
        // }
        // cout<<"\n";
        // for(auto a:m2){
        //     cout<<a->val<<" ";
        // }
        while( i<m1.size() && j<m2.size() && m1[i]==m2[j]){
            ans=m1[i];
            i++;
            j++;
        }
        
        return ans;
        
        
    }
};