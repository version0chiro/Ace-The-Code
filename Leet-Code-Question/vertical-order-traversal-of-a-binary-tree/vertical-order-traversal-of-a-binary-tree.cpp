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
    int sCol=INT_MAX,eCol=INT_MIN,sRow=INT_MAX,eRow=INT_MIN;
    map<pair<int,int>,vector<int>> m;
    void solve(TreeNode* root,int col,int row){
        if(!root) return;
        
        sCol=min(col,sCol),eCol=max(col,eCol);
        sRow=min(row,sRow),eRow=max(row,eRow);
        m[{row,col}].push_back(root->val);
        solve(root->left,col-1,row+1);
        solve(root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> ans;
        vector<int> temp;
        
        for(int i=sCol;i<=eCol;i++){
            for(int j=sRow;j<=eRow;j++){
                if(m.find({j,i})!=m.end()){
                    if(m[{j,i}].size()>1)
                        sort(m[{j,i}].begin(),m[{j,i}].end());

                    for(auto a:m[{j,i}]){
                        temp.push_back(a);
                    }
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};