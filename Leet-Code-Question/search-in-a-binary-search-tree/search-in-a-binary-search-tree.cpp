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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                if(temp->val==val){
                    return temp;
                }
                if(temp->left && val<temp->val){
                    q.push(temp->left);
                } else if(temp->right && val>temp->val){
                    q.push(temp->right);
                }
                
            }
        }
        return NULL;
    }
};