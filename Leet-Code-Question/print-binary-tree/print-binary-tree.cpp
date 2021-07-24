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
    int height(TreeNode* root,int h){
        if(!root) return 0;
        
        int l = height(root->left,h+1);
        
        int r = height(root->right,h+1);
        
        return max(l,r)+1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        
        int height_of_tree = height(root,0);
        int width_of_tree = pow(2,height_of_tree)-1;
        int normalization = (width_of_tree-1)/2;
        vector<vector<string>> ans(height_of_tree,vector<string>(width_of_tree,""));
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,normalization});
        int level=1;
        
        while(q.size()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto temp = q.front();
                auto node = temp.first;
                int pos = temp.second;
                q.pop();
                // cout<<level<<" "<<pos<<" ";
                ans[level-1][pos]=to_string(node->val);
                
                if(node->left)
                    q.push({node->left,pos-pow(2,height_of_tree-level-1)});
                if(node->right)
                    q.push({node->right,pos+pow(2,height_of_tree-level-1)});
                
            }
            // cout<<"\n";
            level++;
        }
        
        return ans;
    }
};