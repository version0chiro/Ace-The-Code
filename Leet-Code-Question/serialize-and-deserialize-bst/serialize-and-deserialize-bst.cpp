/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    inline void inorderDFS(TreeNode* root,string &order){
        if(!root) return;
        char buff[4];
        
        memcpy(buff,&(root->val),sizeof(int));
        
        for(int i=0;i<4;i++){
            order.push_back(buff[i]);
        }
        inorderDFS(root->left,order);
        inorderDFS(root->right,order);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        inorderDFS(root,order);
        return order;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos=0;
        return reconstruct(data,pos,INT_MIN,INT_MAX);
    }
    
    inline TreeNode* reconstruct(const string& buffer,int& pos,int minValue,int maxValue){
        if(pos>=buffer.size()) return NULL;
        int value;
        memcpy(&value,&buffer[pos],sizeof(int));
        if(value<minValue || value>maxValue) return NULL;
        TreeNode* root = new TreeNode(value);
        
        pos+=sizeof(int);
        root->left = reconstruct(buffer,pos,minValue,value);
        root->right = reconstruct(buffer,pos,value,maxValue);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;