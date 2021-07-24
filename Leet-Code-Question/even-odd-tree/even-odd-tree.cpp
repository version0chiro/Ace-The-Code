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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        
        int level=0;
        
        while(!q.empty()){
            int s=q.size();
            int last = (level % 2) ? INT_MAX : INT_MIN;
            for(int i=0;i<s;i++){
                auto temp = q.front();
                int tempV=temp->val;
                q.pop();
                
                if(level%2 == tempV%2) return false;
                if(level%2 && tempV>=last) return false;
                if(!(level%2) && tempV<=last) return false;
                
                last=tempV;
                if(temp->left) q.push(temp->left);
                
                if(temp->right) q.push(temp->right);
            }
            level++;
        }
    
        
    
        return true;
    }
    
    
    
};