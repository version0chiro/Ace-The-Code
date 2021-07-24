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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;
        queue<TreeNode*> q;
        // bool switch = false;
        bool switchFlag = false;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            vector<int> in_ans;            
            cout<<endl;
            for(int i=0;i<s;i++){
                auto temp = q.front();
                in_ans.push_back(temp->val);
                cout<<temp->val<<" ";
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(switchFlag){
                reverse(in_ans.begin(),in_ans.end());
                switchFlag = false;
            }else{
                switchFlag = true;
            }
            ans.push_back(in_ans);
        }
        
        return ans;
    }
};