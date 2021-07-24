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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;

        while(q.size()){
            int s=q.size();
            vector<int> tempVec;
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    tempVec.push_back(temp->left->val);
                }else{
                    tempVec.push_back(-1);
                }
                if(temp->right){
                    q.push(temp->right);
                    tempVec.push_back(temp->right->val);
                }else{
                    tempVec.push_back(-1);
                }
            }
            if(flag){
                for(auto a:tempVec) if(a!=-1) return false;
            }
                
            if(!flag){
                
                for(int i=0;i<tempVec.size();i++){
                    // cout<<tempVec[i]<<" ";
                    if(flag && tempVec[i]!=-1) if(q.size()) return false;
                    if(tempVec[i]==-1) flag=true;
                }
            }
            
            // cout<<endl;
            
        }
        
        return true;
    }
};