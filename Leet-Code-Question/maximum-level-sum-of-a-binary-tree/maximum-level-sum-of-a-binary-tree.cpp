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
    int maxLevelSum(TreeNode* root) {
        int ans;
        unordered_map<int,int> m;
        
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(!q.empty()){
            int tempSum=0;
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                tempSum+=temp->val;
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            m[level]=tempSum;
            level++;
        }
        int maxElement = INT_MIN;
        for(auto a:m){
            cout<<a.first<<" "<<a.second<<"\n";
            if(a.second>=maxElement){
                ans = a.first;
                maxElement = a.second;
            }
        }
        
        return ans;
    }
};