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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            depth++;
            int s = q.size();
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        
        return depth;
    }
};