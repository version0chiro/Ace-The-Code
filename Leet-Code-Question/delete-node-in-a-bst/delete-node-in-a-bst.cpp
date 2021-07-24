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
    TreeNode* findMin(TreeNode* root){
        while(root && root->left){
            root=root->left;
        }
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            if(!root->left && !root->right){
                return NULL;
            }
            else if(!root->left){
                auto temp = root->right;
                delete root;
                return temp;
            }else if(!root->right){
                auto temp = root->left;
                delete root;
                return temp;
            }
            
            auto temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);
            
        }
        
        
        return root;
    }
};