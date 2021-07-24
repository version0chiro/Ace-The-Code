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
    vector<int> ans;
    bool flag=true;
    void solve(TreeNode* root){
        if(!root || !flag) return;
        solve(root->left);
        if(ans.size() && ans.back()>=root->val){
            flag=false;
            return;
        }
        ans.push_back(root->val);
        solve(root->right);
    }
	bool isValidBST(TreeNode* root) {
        solve(root);
        return flag;
	}
};