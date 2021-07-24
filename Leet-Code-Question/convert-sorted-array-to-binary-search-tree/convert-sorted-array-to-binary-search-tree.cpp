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
    TreeNode* solve(int l,int r,vector<int> nums){
        if(l>r){
            return NULL;
        }
        int m=(l+r)/2;
        TreeNode* t = new TreeNode(nums[m]);
        t->left = solve(l, m-1, nums);
        t->right = solve(m+1,r,nums);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        
        return solve(l,r,nums);
    }
};