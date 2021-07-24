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
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> q;
        int minDistance = INT_MAX;
        vector<int> v;
        
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                
                v.push_back(temp->val);
                if(temp->left){
                    
                    q.push(temp->left);
                }
                if(temp->right){
                    
                    q.push(temp->right);
                }
            }
        }
        
        sort(v.begin(),v.end());
        
        for(int i=1;i<v.size();i++){
            minDistance=min(minDistance,abs(v[i]-v[i-1]));
        }
        
        return minDistance;
    }
};