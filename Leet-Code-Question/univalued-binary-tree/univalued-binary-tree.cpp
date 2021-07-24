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
    
    bool isUnivalTree(TreeNode* root) {
        unordered_map<int,int> m;
        queue<TreeNode*> q;
        m[root->val]++;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                if(m.find(temp->val)==m.end()){
                    return false;
                }else{
                    m[temp->val]++;
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        
        
        return true;
        
    }
};