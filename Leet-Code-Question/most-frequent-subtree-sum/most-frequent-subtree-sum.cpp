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
    unordered_map<int,int> m;
    int maxCount=INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int sum=root->val+solve(root->left)+solve(root->right);
        m[sum]++;
        maxCount=max(m[sum],maxCount);
        // ans.push_back(sum);
        
        return sum;
        
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<int> ans;
        
        for(auto a:m){
            if(a.second==maxCount)
                ans.push_back(a.first);
        }
        
        return ans;
    }
};