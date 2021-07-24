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
    vector<int> nodes;
    void inOrder(TreeNode* root){
        if(!root) return;
        
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }
    
    TreeNode* formTree(TreeNode* root,int l,int r){
        int mid=l+ (r-l)/2;
        // cout<<" for l :"<<l<<" and r :"<<r<<" ";
        // cout<<mid<<" "<<nodes[mid]<<" \n";
        
        // if(mid<l || mid>=r+1) return NULL;
        
        if(mid!=l && l!=r){
            root->left = new TreeNode(0);
            root->left = formTree(root->left,l,mid-1);
        }
        
        if(mid!=r && l!=r){
            root->right=new TreeNode(0);
            root->right = formTree(root->right,mid+1,r);
        }
        
        root->val=nodes[mid];
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        // for(auto a:nodes){
        //     cout<<a<<" ";
        // }
        return formTree(new TreeNode(0),0,nodes.size()-1);
    }
};