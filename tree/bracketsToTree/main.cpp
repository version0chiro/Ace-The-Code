#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left,*right;
};


Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}



int findIndex(string str,int si,int ei){
    if(si>ei) return -1;

    stack<char> s;

    for(int i=si; i<=ei;i++){
        if(str[i]=='(')
            s.push(str[i]);
        else if(str[i]==')')
            if(s.top()=='('){
                s.pop();

                if(s.empty()){
                    return i;
                }
            }
    }
    return -1;
}

Node* treeFromString(string str,int si,int ei){
    if(si>ei) return NULL;

    Node* root = newNode(str[si]-'0');
    int index = -1;

    if(si+1 <= ei && str[si+1]=='(')
        index = findIndex(str,si+1,ei);
    
    if(index!=-1){
        root->left = treeFromString(str,si+2,index-1);

        root->right = treeFromString(str,index+2,ei-1);

    }

    return root;
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
int main(){
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str,0,str.length()-1);
    // Node* root = newNode((int)(str[0]-'0'));
    preOrder(root);
    return 0;
}